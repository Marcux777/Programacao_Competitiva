#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> ans = nums;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

//Teste
int main(){
    vector<int> n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(3);
    Solution x;
    n = x.getConcatenation(n);
    for(int i = 0; i < n.size(); i++){
        cout << n[i] << " ";
    }

}