
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // número de linhas
        if (m == 0) return false;
        int n = matrix[0].size(); // número de colunas
        if (n == 0) return false;
        
        // busca binária para encontrar a linha em que o valor pode estar
        int lo = 0, hi = m - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (matrix[mid][0] <= target) lo = mid;
            else hi = mid - 1;
        }
        
        // busca binária na linha encontrada para encontrar o valor exato
        int row = lo;
        lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return false;
    }
};

int main()
{
    vector<vector<int>> V = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int proc = 3;
    Solution sol;
    cout << sol.searchMatrix(V, proc) << endl;
}