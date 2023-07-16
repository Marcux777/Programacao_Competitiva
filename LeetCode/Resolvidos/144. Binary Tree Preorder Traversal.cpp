#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definição da estrutura da árvore binária
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root) {
            return v;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* aux = s.top();
            v.push_back(aux->val);
            s.pop();
            if (aux->right) {
                s.push(aux->right);
            }
            if (aux->left) {
                s.push(aux->left);
            }
        }
        return v;
    }
};

int main() {
    Solution solution;

    // Criação da árvore binária
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Chamada da função preorderTraversal
    vector<int> result = solution.preorderTraversal(root);

    // Imprime os valores dos nós em ordem
    cout << "Travessia pré-ordem (preorder traversal): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
