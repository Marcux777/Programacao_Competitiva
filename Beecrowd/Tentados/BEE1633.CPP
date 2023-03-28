#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int t, c;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> c;
            pq.push(make_pair(t, c));
        }
        int Total = 0, TempoExe = 1;
        while (!pq.empty())
        {
            if (pq.top().first <= TempoExe)
            {
                auto process = pq.top();
                pq.pop();
                if (process.first > TempoExe)
                {

                    Total += TempoExe - process.first;
                }
                else
                {
                    TempoExe = process.first;
                }
                TempoExe += process.second;
            }
        }
        cout << Total << endl;
    }
    return 0;
}
