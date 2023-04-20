#include <bits/stdc++.h>

using namespace std;

// Definição da estrutura de uma lista encadeada
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // Cria uma nova lista encadeada vazia
        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        // Percorre as duas listas simultaneamente até que uma delas seja totalmente percorrida
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // Adiciona o restante da primeira lista, se houver
        if (l1 != NULL)
        {
            cur->next = l1;
        }

        // Adiciona o restante da segunda lista, se houver
        if (l2 != NULL)
        {
            cur->next = l2;
        }

        // Retorna a nova lista encadeada, ignorando o nó vazio inicial
        return head->next;
    }
};

int main()
{
    ListNode *a;
    a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(5);
    ListNode *b;
    b = new ListNode(1);
    b->next = new ListNode(3);
    b->next = new ListNode(4);
    Solution x;
    a = x.mergeTwoLists(a, b);
    while (a)
    {
        cout << a->val << " ";
        a = a->next;
    }
}