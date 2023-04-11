#include <bits/stdc++.h>

using namespace std;

// Definição da classe ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* Percorre = head;
        while(Percorre){
            st.push(Percorre->val);
            Percorre = Percorre->next;
        }
        Percorre = head;
        while(!st.empty()){
            if(Percorre->val != st.top()){
                return false;
            }else{
                Percorre = Percorre->next;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "A lista eh um palindromo" << endl;
    } else {
        cout << "A lista nao eh um palindromo" << endl;
    }

    return 0;
}
