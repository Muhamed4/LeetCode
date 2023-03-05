

// Link of Problem
// https://leetcode.com/problems/jump-game-iv/



class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int>bfs;
        map<int,int>ans, vis;
        map<int,set<int>>st;
        int n = (int)arr.size();
        for(int i = 0 ; i < n;i++)st[arr[i]].insert(i);
        bfs.push(0);
        ans[0] = 0;
        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            bool ok = 0;
            if(node == n - 1)break;
            if(!vis.count(arr[node])){
                for(auto child : st[arr[node]]){
                    if(child != node && !ans.count(child)){
                        ans[child] = ans[node] + 1;
                        bfs.push(child);
                    }
                }
            }
            if(node - 1 >= 0){
                if(!ans.count(node - 1)){
                    ans[node - 1] = ans[node] + 1;
                    bfs.push(node - 1);
                }
            }
            if(node + 1 < n){
                if(!ans.count(node + 1)){
                    ans[node + 1] = ans[node] + 1;
                    bfs.push(node + 1);
                }
            }
            vis[arr[node]] = 1;
        }
        return ans[n - 1];
    }
};