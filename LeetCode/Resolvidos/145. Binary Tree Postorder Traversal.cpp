#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrderList;
        if (root == NULL)
            return postOrderList;
        stack<TreeNode *> S;
        S.push(root);
        TreeNode *prev = NULL;
        while (!S.empty())
        {
            auto current = S.top();
            if (prev == NULL || prev->left == current || prev->right == current)
            {
                if (current->left)
                    S.push(current->left);
                else if (current->right)
                    S.push(current->right);
                else
                {
                    S.pop();
                    postOrderList.push_back(current->val);
                }
            }
            else if (current->left == prev)
            {
                if (current->right)
                    S.push(current->right);
                else
                {
                    S.pop();
                    postOrderList.push_back(current->val);
                }
            }
            else if (current->right == prev)
            {
                S.pop();
                postOrderList.push_back(current->val);
            }
            prev = current;
        }
        return postOrderList;
    }
};

int main()
{
    Solution solution;

    // Criação da árvore binária
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Chamada da função postorderTraversal
    vector<int> result = solution.postorderTraversal(root);

    // Imprime os valores dos nós em ordem
    cout << "Travessia pós-ordem (postorder traversal): ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
