

// Link Of Problem

// https://leetcode.com/problems/is-graph-bipartite/

// 785. Is Graph Bipartite?





class Solution {
    bool Is_Bipartite(vector<vector<int>>&adj, int n){
        vector<int> side(n, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int st = 0; st < n; ++st) {
            if (side[st] == -1) {
                q.push(st);
                side[st] = 0;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int u : adj[v]) {
                        if (side[u] == -1) {
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        } else {
                            is_bipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }
        return is_bipartite;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        return Is_Bipartite(graph, (int)graph.size());
    }
};