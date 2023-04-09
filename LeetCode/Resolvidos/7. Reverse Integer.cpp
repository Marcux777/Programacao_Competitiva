#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                return result;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};

int main(){
    Solution a;
    vector<int> v;
    int n, valor, target;
    cin >> n; //quantos elementos vou puxar pro vector
    while(n--){
        cin >> valor;
        v.push_back(valor);
    }
    cin >> target;
    vector<int> final = a.twoSum(v, target);

    for(auto it : final){
        cout << it << " ";
    }
}