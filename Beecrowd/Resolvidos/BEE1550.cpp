#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int reverseDigits(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int bfs(int A, int B)
{
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push(make_pair(A, 0));

    while (!q.empty())
    {
        int current = q.front().first;
        int operations = q.front().second;
        q.pop();

        visited.insert(current);

        if (current == B)
        {
            return operations;
        }

        int nextNum = current + 1;
        if (visited.find(nextNum) == visited.end())
        {
            q.emplace(nextNum, operations + 1);
        }

        int reversedNum = reverseDigits(current);
        if (visited.find(reversedNum) == visited.end())
        {
            q.emplace(reversedNum, operations + 1);
        }
    }

    return -1;
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--)
    {
        int A, B;
        cin >> A >> B;
        cout << bfs(A, B) << endl;
    }
}
