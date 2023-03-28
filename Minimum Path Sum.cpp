

// Link Of Problem

// https://leetcode.com/problems/minimum-path-sum/

// 64. Minimum Path Sum







class Solution {
    int m, n, dp[222][222];
    // bool valid(int i, int j){
    //     return (i >= 0 && i < n && j >= 0 && j < m);
    // }
    int DFS(vector<vector<int>>&v, int i, int j)
    {
        if (i >= m || j >= n) return 1e8;
        if (i == m - 1 && j == n - 1) return v[m - 1][n - 1];
        int &ret = dp[i][j];
        if (~ret) return ret;
        return ret = min(DFS(v, i, j + 1), DFS(v, i + 1, j)) + v[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        m = grid.size(); n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return DFS(grid, 0, 0);
    }
};