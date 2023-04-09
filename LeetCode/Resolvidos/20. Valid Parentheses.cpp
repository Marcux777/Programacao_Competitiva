#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (c == ')' && !st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    if (c == '}' && !st.empty() && st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        if (c == ']' && !st.empty() && st.top() == '[')
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution x;
    string str;
    while (cin >> str)
    {
        if (x.isValid(str))
        {
            cout << "true\n";
        }
        else
        {
            cout << "false\n";
        }
    }
}