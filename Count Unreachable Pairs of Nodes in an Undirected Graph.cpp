
// Link of Problem

// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph








class Solution {
    int DFS(vector<vector<int>>&adj, vector<int>&vis, int node){
        vis[node] = 1;
        int ret = 1;
        for(auto child: adj[node]){
            if(!vis[child])ret += DFS(adj, vis, child);
        }
        return ret;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            int x = it[0], y = it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(n);
        vector<long long>cnt, cur;
        for(int i = 0 ; i < n;i++){
            if(!vis[i])cnt.push_back(DFS(adj, vis, i));
        }
        cur = cnt;
        // for(auto it : cur)cout << it << ' ';
        long long res = 0;
        for(int i = (int)cnt.size() - 2; i >= 0;i--)cnt[i] += cnt[i + 1];
        for(int i = 0; i < (int)cur.size() - 1;i++){
            res += (cur[i] * cnt[i + 1]);
        }
        return res;
    }
};