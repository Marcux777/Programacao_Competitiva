#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    char D;
    Node *left;
    Node *right;
    static Node *MontaNode(char dat)
    {
        Node *P = new Node;
        if (P)
        {
            P->D = dat;
            P->left = NULL;
            P->right = NULL;
        }
        return P;
    }
    static string DesmontaNode(Node *P)
    {
        string X;
        if (P)
        {
            X = P->D;
            delete P;
        }
        return X;
    }
};

Node *buildTreeHelper(const string &pre, const string &in)
{
    if (pre.empty())
    {
        return nullptr;
    }
    char root_val = pre[0];
    int root_idx = in.find(root_val);
    string left_in = in.substr(0, root_idx);
    string right_in = in.substr(root_idx + 1);
    string left_pre = pre.substr(1, root_idx);
    string right_pre = pre.substr(root_idx + 1);
    Node *root = Node::MontaNode(root_val);
    root->left = buildTreeHelper(left_pre, left_in);
    root->right = buildTreeHelper(right_pre, right_in);
    return root;
}

Node *buildTree(const string &pre, const string &in)
{
    return buildTreeHelper(pre, in);
}

void printPostOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->D;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string pre, in;
    while (cin >> pre >> in)
    {
        Node *root = buildTree(pre, in);
        printPostOrder(root);
        cout << endl;
        cin.sync();
    }
    return 0;
}
