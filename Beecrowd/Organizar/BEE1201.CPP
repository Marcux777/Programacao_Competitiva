#include <iostream>
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

    void Delete(Trem x)
    {
        Root = pop(Root, x);
        N--;
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

    bool Insert(Trem x)
    {
        insere(&Root, x);
        N++;
        return true;
    }

    void InOrder()
    {
        if (!Root)
        {
            return;
        }

        int aux = 0;
        PrintInOrder(Root, &aux);
    }

    void PreOrder()
    {
        if (!Root)
        {
            return;
        }
        int aux = 0;
        PrintPreOrder(Root, &aux);
    }

    void PosOrder()
    {
        if (!Root)
        {
            return;
        }
        int aux = 0;
        PrintPosOrder(Root, &aux);
    }

    bool IsEmpty()
    {
        return Root == NULL;
    }

private:
    void PrintPosOrder(Node<Trem> *P, int *aux)
    {
        if (!P)
        {
            return;
        }
        PrintPosOrder(P->left, aux);
        PrintPosOrder(P->right, aux);
        if (*aux == 0)
        {
            *aux = 1;
            cout << P->D;
        }
        else
        {
            cout << " " << P->D;
        }
    }

    void PrintPreOrder(Node<Trem> *P, int *aux)
    {
        if (P == NULL)
        {
            return;
        }

        if (*aux == 0)
        {
            cout << P->D;
            *aux = 1;
        }
        else
        {
            cout << " " << P->D;
        }
        PrintPreOrder(P->left, aux);
        PrintPreOrder(P->right, aux);
    }

    void PrintInOrder(Node<Trem> *P, int *aux)
    {
        if (!P)
        {
            return;
        }
        PrintInOrder((P->left), aux);
        if (*aux == 0)
        {

            cout << P->D;
            *aux = 1;
        }
        else
        {
            cout << " " << P->D;
        }
        PrintInOrder((P->right), aux);
    }

    void insere(Node<Trem> **raiz, Trem valor)
    {
        if ((*raiz) == NULL)
        {
            Node<Trem> *r = Node<Trem>::MontaNode(valor);
            (*raiz) = r;
        }
        else
        {
            if (valor > (*raiz)->D)
            {
                insere(&(*raiz)->right, valor);
            }
            else
            {
                insere(&(*raiz)->left, valor);
            }
        }
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

    Node<Trem> *findMax(Node<Trem> *P)
    {
        if (P)
        {
            Node<Trem> *q = P;
            while (q && q->right != NULL)
            {
                q = q->right;
            }
            return q;
        }
        return NULL;
    }

    Node<Trem> *pop(Node<Trem> *root, Trem x)
    {
        Node<Trem> *tmp;
        if (!root)
            return NULL;
        else if (root->D > x)
            root->left = pop(root->left, x);
        else if (root->D < x)
            root->right = pop(root->right, x);
        else if (root->left && root->right)
        {

            tmp = findMax(root->left);
            root->D = tmp->D;
            root->left = pop(root->left, root->D);
        }
        else
        {

            tmp = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;

            Node<Trem>::DesmontaNode(tmp);
        }

        return root;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("entrada.txt", "r", stdin);
    // freopen("saida.txt", "w", stdout);
    string operacao;
    int num;
    BTree<int> Arv;
    while (cin >> operacao)
    {
        if (operacao == "I")
        {
            cin >> num;
            Arv.Insert(num);
        }
        else
        {
            if (operacao == "INFIXA")
            {
                if (!Arv.IsEmpty())
                {
                    Arv.InOrder();
                }
                cout << endl;
            }
            else
            {
                if (operacao == "PREFIXA")
                {
                    if (!Arv.IsEmpty())
                    {
                        Arv.PreOrder();
                    }
                    cout << endl;
                }
                else
                {
                    if (operacao == "POSFIXA")
                    {
                        if (!Arv.IsEmpty())
                        {
                            Arv.PosOrder();
                        }
                        cout << endl;
                    }
                    else
                    {
                        if (operacao == "P")
                        {
                            cin >> num;
                            if (Arv.Search(num))
                            {
                                cout << num << " existe" << endl;
                            }
                            else
                            {
                                cout << num << " nao existe" << endl;
                            }
                        }
                        else
                        {
                            if (operacao == "R")
                            {
                                int dado;
                                cin >> dado;

                                Arv.Delete(dado);
                            }
                            else
                            {
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }
        cin.sync(); // Limpar o buffer
    }
}
