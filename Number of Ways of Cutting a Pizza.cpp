
// Link Of Problem

// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

// 1444. Number of Ways of Cutting a Pizza







class Solution {
    const int mod = 1000000007;
    vector<vector<int>>pr;
    int dp[55][55][12], n, m;
    int sum(int x1, int x2, int y1, int y2){
        return pr[x2][y2] - pr[x1 - 1][y2] - pr[x2][y1 - 1] + pr[x1 - 1][y1 - 1];
    }
    int sol(int l, int s, int rem){
        if(rem == 1)return rem;
        int &ret = dp[l][s][rem];
        if(~ret)return ret;
        ret = 0;
        for(int i = l;i < n;i++){
            int cnt1 = sum(l, i, s,m);
            int cnt2 = sum(i + 1, n, s , m);
            if(cnt1 && cnt2)ret = (ret % mod) + (sol(i + 1, s, rem - 1) % mod);
        }
        for(int i = s; i < m;i++){
            int cnt1 = sum(l, n, s, i);
            int cnt2 = sum(l, n, i + 1, m);
            if(cnt1 && cnt2)ret = (ret % mod) + (sol(l, i + 1, rem - 1) % mod);
        }
        return ret % mod;
    }
public:
    int ways(vector<string>& pizza, int k) {
        n = (int)pizza.size(), m = (int)pizza[0].size();
        pr = vector<vector<int>>(n + 2, vector<int>(m + 2));
        for(int i = 0; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(pizza[i][j] == 'A'){
                    pr[i + 1][j + 1] = 1;
                }
            }
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m;j++){
                pr[i][j] += pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1];
            }
        }
        memset(dp, -1, sizeof(dp));
        return sol(1, 1, k);
    }
};