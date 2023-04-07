

// Link Of Problem

// https://leetcode.com/problems/number-of-enclaves/

// 1020. Number of Enclaves







class Solution {
    int n, m;
    int vis[555][555];
    bool valid(int x,int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    void DFS(int x, int y, vector<vector<int>>&v){
        if(!valid(x, y) || vis[x][y] || !v[x][y])return;
        vis[x][y] = 1;
        DFS(x + 1, y, v);
        DFS(x - 1, y, v);
        DFS(x, y - 1, v);
        DFS(x, y + 1, v);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = (int)grid.size(), m = (int)grid[0].size();
        for(int i = 0; i < m;i++){
            if(grid[0][i] == 1 && !vis[0][i])DFS(0, i, grid);
            if(grid[n - 1][i] == 1 && !vis[n - 1][i])DFS(n - 1, i, grid);
        }
        for(int i = 0 ; i < n;i++){
            if(grid[i][0] == 1 && !vis[i][0])DFS(i, 0, grid);
            if(grid[i][m - 1] == 1 && !vis[i][m - 1])DFS(i, m - 1, grid);
        }
        int ans = 0;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                ans += (grid[i][j] && !vis[i][j]);
            }
        }
        return ans;
    }
};