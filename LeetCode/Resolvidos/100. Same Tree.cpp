#include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if((!p) && (!q)){
            return true;
        }
        return (p && q) && (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};

int main()
{
    // criando duas árvores binárias
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(3);
    tree1->right = new TreeNode(4);

    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(3);
    tree2->right = new TreeNode(5);

    // criando um objeto da classe Solution
    Solution solution;

    // chamando a função isSameTree e armazenando o resultado na variável 'result'
    bool result = solution.isSameTree(tree1, tree2);

    // imprimindo o resultado
    if (result)
    {
        std::cout << "As arvores sao iguais\n";
    }
    else
    {
        std::cout << "As arvores sao diferentes\n";
    }

    // liberando a memória alocada para as árvores
    delete tree1;
    delete tree2;

    return 0;
}
