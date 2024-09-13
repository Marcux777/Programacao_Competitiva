#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cont;

struct node
{
    int val;
    node *left;
    node *right;
};

node *newNode(int item)
{
    node *temp = new node();
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->val;
        if (cont > 1)
        {
            cout << " ";
        }
        cont--;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val;
        if (cont > 1)
        {
            cout << " ";
        }
        cont--;
        inOrder(root->right);
    }
}

int postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val;
        if (cont > 1)
        {
            cout << " ";
        }
        cont--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        node *root = NULL;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        cout << "Case " << i << ":" << endl;
        cout << "Pre.: ";
        cont = n;
        preOrder(root);
        cout << endl
             << "In..: ";
        cont = n;
        inOrder(root);
        cout << endl
             << "Post: ";
        cont = n;
        postOrder(root);
        cout << endl
             << endl;
    }
    return 0;
}