
// Link Of Problem

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// 2492. Minimum Score of a Path Between Two Cities









class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        map<int,int>vis;
        vector<vector<pair<int,int>>>adj(n + 2);
        for(int i = 0 ; i < roads.size();i++){
            int x = roads[i][0], y = roads[i][1], z = roads[i][2];
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        int ans = 100000000;
        queue<int>bfs;
        bfs.push(1);
        vis[1] = 0;
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            //if(node == n)break;
            for(auto child: adj[node]){
                ans = min(ans, child.second);
                if(!vis.count(child.first)){
                    vis[child.first] = 1;
                    bfs.push(child.first);
                }
                else if(child.second < vis[child.first]){
                    vis[child.first] = 1;
                    bfs.push(child.first);
                }
            }
        }
        return ans;
    }
};