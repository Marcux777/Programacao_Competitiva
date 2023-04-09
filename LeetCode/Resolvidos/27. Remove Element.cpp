#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*A função remove encontra o primeiro elemento que é igual ao valor especificado e o move para o final do vector. 
Em seguida, a função erase remove todos os elementos do final do vector que correspondem ao valor especificado. 
Esse processo é repetido até que não haja mais elementos iguais ao valor especificado.*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        sort(nums.begin(), nums.end());
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main()
{
    vector<int> n = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution x;
    cout << x.removeElement(n, val) << endl;
}