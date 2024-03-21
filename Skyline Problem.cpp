class Solution {
public:
    vector<vector<int>> build(vector<vector<int>>& b){
        int n = b.size();
        vector<pair<int, int>> d2, sky;
        for(int i = 0; i < n; i++){
            d2.push_back({b[i][0], -b[i][1]});
            d2.push_back({b[i][2], b[i][1]});
        }
        sort(d2.begin(), d2.end());
        
        priority_queue<int> pq;
        for(auto i : sky){
            pq.push(i.second);
        }
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
    }
};