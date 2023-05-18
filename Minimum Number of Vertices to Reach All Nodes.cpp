

// Link Of Problem

// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// 1557. Minimum Number of Vertices to Reach All Nodes



class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &it: edges){
            int x = it[0], y = it[1];
            adj[y].push_back(x);
        }
        vector<int>ans;
        for(int i = 0 ; i < n;i++){
            if((int)adj[i].size() == 0)ans.push_back(i);
        }
        return ans;
    }
};