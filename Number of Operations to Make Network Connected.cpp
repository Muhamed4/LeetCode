
// Link Of Problem

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// 1319. Number of Operations to Make Network Connected









class Solution {
    void DFS(vector<vector<int>>&adj, vector<int>&vis, int node){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(!vis[child])DFS(adj, vis, child);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int x = (int)connections.size();
        if(x < n - 1)return -1;
        vector<vector<int>>adj(n + 1);
        for(int i = 0 ; i < connections.size();i++){
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n + 1);
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                ans++;
                DFS(adj, vis, i);
            }
        }
        return ans - 1;
    }
};