#include <iostream>
#include <vector>
using namespace std;

template <typename Trem>
class Node
{
public:
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
    static Trem DesmontaNode(Node<Trem> *P)
    {
        Trem X;
        if (P)
        {
            X = P->D;
            delete P;
        }
        return X;
    }
};

vector<char> v[3];

template <typename Trem>
class BTree
{
public:
    Node<Trem> *Root; // Nó raiz
    int N;            // Para Contar quantos nós temos

    // Metodos:
    BTree()
    {
        Root = NULL;
        N = 0;
    }

    bool Search(Trem X)
    {
        if (Root == NULL)
        {
            return false;
        }
        Node<Trem> *P = search(Root, X);
        return P != NULL;
    }

    bool insertRecursivo(Trem x)
    {
        Root = insertRec(Root, x);
        N++;
        return true;
    }

    void InOrder()
    {
        v[2].clear();
        PrintInOrder(Root);
    }

    void PreOrder()
    {
        v[1].clear();
        PrintPreOrder(Root);
    }

    void PosOrder()
    {
        v[0].clear();
        PrintPosOrder(Root);
    }

private:
    void PrintPosOrder(Node<Trem> *P)
    {
        if (P)
        {
            PrintPosOrder(P->left);
            PrintPosOrder(P->right);
            v[0].push_back(P->D);
        }
        return;
    }

    void PrintPreOrder(Node<Trem> *P)
    {
        if (P)
        {
            v[1].push_back(P->D);
            PrintPreOrder(P->left);
            PrintPreOrder(P->right);
        }
        return;
    }

    void PrintInOrder(Node<Trem> *P)
    {
        if (P)
        {
            PrintInOrder(P->left);
            v[2].push_back(P->D);
            PrintInOrder(P->right);
        }
        return;
    }

    Node<Trem> *insertRec(Node<Trem> *p, Trem x)
    {
        if (p == NULL)
        {
            return Node<Trem>::MontaNode(x);
        }
        if (x < p->D)
        {
            p->left = insertRec(p->left, x);
        }
        else
        {
            if (x > p->D)
            {
                p->right = insertRec(p->right, x);
            }
        }
        return p;
    }

    Node<Trem> *search(Node<Trem> *node, Trem dat)
    {
        if (node == NULL || node->D == dat)
        {
            return node;
        }

        if (dat < node->D)
        {
            return search(node->left, dat);
        }
        else
        {
            return search(node->right, dat);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string operacao;
    char letra;
    BTree<char> Arv;
    while (cin >> operacao)
    {
        if (operacao == "I")
        {
            cin >> letra;
            Arv.insertRecursivo(letra);
        }
        else
        {
            if (operacao == "INFIXA")
            {
                Arv.InOrder();
                for (int i = 0; i < v[2].size(); i++)
                {
                    cout << v[2][i];
                    if (i < v[2].size() - 1)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            else
            {
                if (operacao == "PREFIXA")
                {
                    Arv.PreOrder();
                    for (int i = 0; i < v[1].size(); i++)
                    {
                        cout << v[1][i];
                        if (i < v[1].size() - 1)
                        {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
                else
                {
                    if (operacao == "POSFIXA")
                    {
                        Arv.PosOrder();
                        for (int i = 0; i < v[0].size(); i++)
                        {
                            cout << v[0][i];
                            if (i < v[0].size() - 1)
                            {
                                cout << " ";
                            }
                        }
                        cout << endl;
                    }
                    else
                    {
                        if (operacao == "P")
                        {
                            cin >> letra;
                            if (Arv.Search(letra))
                            {
                                cout << letra << " existe" << endl;
                            }
                            else
                            {
                                cout << letra << " nao existe" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}