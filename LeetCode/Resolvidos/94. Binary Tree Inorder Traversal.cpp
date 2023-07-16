#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definição da estrutura da árvore binária
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (!root)
        {
            return v;
        }
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (curr != NULL || !s.empty())
        {

            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            v.push_back(curr->val);
            s.pop();

            curr = curr->right;
        }
        return v;
    }
};

int main()
{
    Solution solution;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = solution.inorderTraversal(root);

    cout << "Travessia em ordem (inorder traversal): ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
