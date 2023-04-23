#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // freopen("saida.txt", "w", stdout);
  int N;
  cin >> N;
  while (N--)
  {
    int M, C;
    cin >> M >> C;
    vector<vector<int>> table(M);
    while (C--)
    {
      int key;
      cin >> key;
      int index = key % M;
      table[index].push_back(key);
    }
    for (int i = 0; i < M; i++)
    {
      cout << i;
      for (int j = 0; j < table[i].size(); j++)
      {
        cout << " -> " << table[i][j];
      }
      cout << " -> " << '\\' << endl;
    }
    if (N)
    {
      cout << endl;
    }
  }
  return 0;
}
