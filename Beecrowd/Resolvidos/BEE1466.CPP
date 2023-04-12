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
    static Trem DesmontaNode(Node *P)
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
    int N;
    BTree<Trem>()
    {
        Root = NULL;
        N = 0;
    }

    bool insertRecursivo(Trem x)
    {
        Root = insertRec(Root, x);
        N++;
        return true;
    }

    void ImprimeLVLOrder(Node<Trem> *P)
    {
        int h = Profundidade(P);
        for (int i = 1; i <= h; i++)
        {
            ImprimeLVLOrder(P, i);
        }
        cout << endl;
    }

private:
    int Profundidade(Node<Trem> *P)
    {
        if (!P)
        {
            return 0;
        }
        int esquerda = Profundidade(P->left);
        int direita = Profundidade(P->right);

        if (esquerda > direita)
        {
            return esquerda + 1;
        }
        return direita + 1;
    }

    void ImprimeLVLOrder(Node<Trem> *P, int Altura)
    {
        if (!P)
        {
            return;
        }
        if (Altura == 1)
        {
            cout << P->D;
            if (N > 1)
            {
                cout << " ";
                N--;
            }
        }
        else
        {
            ImprimeLVLOrder(P->left, Altura - 1);
            ImprimeLVLOrder(P->right, Altura - 1);
        }
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
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        BTree<int> Arv;
        int n, aux;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            Arv.insertRecursivo(aux);
        }
        cout << "Case " << k + 1 << ":" << endl;
        Arv.ImprimeLVLOrder(Arv.Root);
        cout << endl;
    }
}