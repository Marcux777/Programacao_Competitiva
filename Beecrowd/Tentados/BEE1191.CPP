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
    

};