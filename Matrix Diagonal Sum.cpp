
// Link Of Problem

// https://leetcode.com/problems/matrix-diagonal-sum/

// 1572. Matrix Diagonal Sum



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = (int)mat.size();
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ;j < n;j++){
                if(i == j)ans += mat[i][j];
                if(i == n - j - 1)ans += mat[i][j];
            }
        }
        if(n&1)ans -= mat[n / 2][n / 2];
        return ans;
    }
};