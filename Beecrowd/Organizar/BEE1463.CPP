#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

template <typename Trem>
struct Node
{
    Trem D;
    Node *left;
    Node *right;
    static Node *MontaNode(Trem dat)
    {
        Node<Trem> *P = new Node<Trem>;
        if (P)
        {
            P->D = dat;
            P->left = NULL;
            P->right = NULL;
        }
        return P;
    }
};
template <typename Trem>
class expTree
{
public:
    Node<Trem> *Root;

    void Print()
    {
        printLevelOrder(Root);
    }
    void MontaArvore(string expression)
    {
        Root = constructExpressionTree(expression);
    }

    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int precedence(char c)
    {
        if (c == '+' || c == '-')
        {
            return 1;
        }
        else if (c == '*' || c == '/')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

private:
    Node<char> *constructExpressionTree(string expression)
    {
        stack<Node<char> *> nodeStack;
        stack<char> operatorStack;

        // Verifica se o primeiro caractere é um operador, e adiciona um zero à pilha de nós se for
        if (isOperator(expression[0]))
        {
            Node<char> *zeroNode = Node<char>::MontaNode('0');
            nodeStack.push(zeroNode);
        }

        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];

            if (c == ' ')
            {
                continue;
            }
            else if (isdigit(c) || isalpha(c))
            {
                Node<char> *newNode = Node<char>::MontaNode(c);
                nodeStack.push(newNode);
            }
            else if (isOperator(c))
            {
                while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top()))
                {
                    Node<char> *rightNode = nodeStack.top();
                    nodeStack.pop();

                    Node<char> *leftNode = nodeStack.top();
                    nodeStack.pop();

                    Node<char> *newNode = Node<char>::MontaNode(operatorStack.top());
                    newNode->left = leftNode;
                    newNode->right = rightNode;

                    nodeStack.push(newNode);
                    operatorStack.pop();
                }

                operatorStack.push(c);
            }
            else if (c == '(')
            {
                operatorStack.push(c);
            }
            else if (c == ')')
            {
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    Node<char> *rightNode = nodeStack.top();
                    nodeStack.pop();

                    Node<char> *leftNode = nodeStack.top();
                    nodeStack.pop();

                    Node<char> *newNode = Node<char>::MontaNode(operatorStack.top());
                    newNode->left = leftNode;
                    newNode->right = rightNode;

                    nodeStack.push(newNode);
                    operatorStack.pop();
                }

                operatorStack.pop();
            }
        }

        while (!operatorStack.empty())
        {
            Node<char> *rightNode = nodeStack.top();
            nodeStack.pop();

            Node<char> *leftNode = nodeStack.top();
            nodeStack.pop();

            Node<char> *newNode = Node<char>::MontaNode(operatorStack.top());
            newNode->left = leftNode;
            newNode->right = rightNode;

            nodeStack.push(newNode);
            operatorStack.pop();
        }

        return nodeStack.top();
    }

    void printLevelOrder(Node<char> *P)
    {
        if (P == NULL)
        {
            return;
        }

        queue<Node<char> *> q;
        q.push(P);

        int level = 0;

        while (!q.empty())
        {
            int size = q.size();

            cout << "Nivel " << level << ": ";

            for (int i = 0; i < size; i++)
            {
                Node<char> *node = q.front();
                q.pop();

                if (isOperator(node->D))
                {
                    cout << node->D;
                }
                else
                {
                    if (node->D != '0')
                    {
                        cout << node->D;
                    }
                }

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            cout << endl;
            level++;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool PrimeiraLinha = true;
    // freopen("saida.txt", "w", stdout);
    string expression;
    while (getline(cin, expression))
    {
        if (PrimeiraLinha)
        {
            PrimeiraLinha = false;
        }
        else
        {
            cout << endl;
        }

        expTree<char> a;
        a.MontaArvore(expression);
        a.Print();
    }

    return 0;
}