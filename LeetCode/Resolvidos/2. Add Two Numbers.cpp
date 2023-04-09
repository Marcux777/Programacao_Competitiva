#include <iostream>

using namespace std;

// Definição da estrutura de uma lista encadeada
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Cria uma nova lista encadeada vazia
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
        
        // Percorre as duas listas simultaneamente até que ambas sejam totalmente percorridas e não haja mais acarretamento
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            
            // Adiciona o dígito de l1, se houver
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Adiciona o dígito de l2, se houver
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Adiciona o resultado da soma à nova lista encadeada
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            // Define o acarretamento para a próxima soma
            carry = sum / 10;
        }
        
        // Retorna a nova lista encadeada, ignorando o nó vazio inicial
        return head->next;
    }
};

// Função principal para testar a solução do problema 2
int main() {
    Solution sol;
    
    // Exemplo de entrada: l1 = [2,4,3], l2 = [5,6,4]
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    // Calcula a soma de l1 e l2
    ListNode* res = sol.addTwoNumbers(l1, l2);
    
    // Imprime o resultado
    while (res != NULL) {
        cout << res->val;
        res = res->next;
        if (res != NULL) {
            cout << " -> ";
        }
    }
    cout << endl;
    
    return 0;
}
