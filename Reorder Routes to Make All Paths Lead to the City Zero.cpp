
// Link of Problem

// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// 1466. Reorder Routes to Make All Paths Lead to the City Zero









class Solution {
    int DFS(vector<vector<int>>&adj, vector<vector<int>>&othadj, vector<int>&vis, int node){
        vis[node] = 1;
        int ret = 0;
        for(auto child: adj[node]){
            if(!vis[child])ret += DFS(adj, othadj, vis, child) + 1;
        }
        for(auto child: othadj[node]){
            if(!vis[child])ret += DFS(adj, othadj, vis, child);
        }
        return ret;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n), othadj(n);
        for(auto it: connections){
            int x = it[0], y = it[1];
            adj[x].push_back(y);
            othadj[y].push_back(x);
        }
        vector<int>vis(n);
        return  DFS(adj, othadj, vis, 0);
    }
};