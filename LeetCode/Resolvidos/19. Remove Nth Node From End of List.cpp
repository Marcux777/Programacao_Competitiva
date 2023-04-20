#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *it = head;
        ListNode *prev = head;

        while (n--)
        {
            it = it->next;
        }
        if (!it)
        {
            return head->next;
        }
        while (it->next)
        {
            prev = prev->next;
            it = it->next;
        }
        ListNode *aux = prev->next;
        prev->next = aux->next;
        delete aux;
        return head;
    }
};

int main()
{
    // Exemplo de lista: 1->2->3->4->5
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    Solution sol;
    int n = 2;
    ListNode *head = sol.removeNthFromEnd(node1, n);

    // Imprime lista resultante
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;

    return 0;
}
