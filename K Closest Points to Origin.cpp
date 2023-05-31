
// Link Of Problem

// https://leetcode.com/problems/k-closest-points-to-origin/

// 973. K Closest Points to Origin





class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>small;
        for(auto &it: points){
            int val = it[0] * it[0] + it[1] * it[1];
            small.push({val, {it[0], it[1]}});
        }
        vector<vector<int>>ans;
        while(k--){
            vector<int> v = {small.top().second.first, small.top().second.second};
            ans.push_back(v);
            small.pop();
        }
        return ans;
    }
};