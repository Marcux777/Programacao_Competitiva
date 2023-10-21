#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
    string sPrime = "#";
    for (char c : s)
    {
        sPrime += c;
        sPrime += "#";
    }

    int n = sPrime.length();
    vector<int> palindromeRadii(n, 0);
    int center = 0;
    int radius = 0;

    for (int i = 0; i < n; i++)
    {
        int mirror = 2 * center - i;

        if (i < radius)
        {
            palindromeRadii[i] = min(radius - i, palindromeRadii[mirror]);
        }

        while (i + 1 + palindromeRadii[i] < n &&
               i - 1 - palindromeRadii[i] >= 0 &&
               sPrime[i + 1 + palindromeRadii[i]] == sPrime[i - 1 - palindromeRadii[i]])
        {
            palindromeRadii[i]++;
        }

        if (i + palindromeRadii[i] > radius)
        {
            center = i;
            radius = i + palindromeRadii[i];
        }
    }

    int maxLength = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (palindromeRadii[i] > maxLength)
        {
            maxLength = palindromeRadii[i];
            centerIndex = i;
        }
    }

    int startIndex = (centerIndex - maxLength) / 2;
    string longestPalindrome = s.substr(startIndex, maxLength);

    return longestPalindrome;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s).size() << endl;
}