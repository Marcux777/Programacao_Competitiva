#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

struct Point
{
    int x, y;
} pts[MAXN];

double dist(Point a, Point b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point a = {x1, y1};
        Point b = {x2, y2};

        double max_dist = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Point p1 = pts[i];
                Point p2 = pts[j];

                double d1 = dist(a, p1) + dist(p1, p2) + dist(p2, b);
                double d2 = dist(a, p2) + dist(p2, p1) + dist(p1, b);

                max_dist = max(max_dist, max(d1, d2));
            }
        }

        cout << fixed << setprecision(2) << max_dist << endl;
    }

    return 0;
}
