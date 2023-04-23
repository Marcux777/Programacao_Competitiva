#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, a, n;
	set<int> st;
	cin >> t;
	while (t--)
	{
		cin >> a;
		while (a--)
		{
			cin >> n;
			st.insert(n);
		}
		cout << st.size() << endl;
		st.clear();
	}
}
