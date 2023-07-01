

// Link Of Problem


// https://leetcode.com/problems/fair-distribution-of-cookies/description/


// 2305. Fair Distribution of Cookies







class Solution {
    void solve(int idx, int k, int n, int& ans, vector<int>&v, vector<int>&a){
        if(idx == n){
            int res = 0;
            for(int i = 0;i < k;i++){
                res = max(res, a[i]);
            }
            ans = min(ans, res);
            return;
        }
        for(int i = 0; i < k;i++){
            a[i] += v[idx];
            solve(idx + 1, k, n, ans, v, a);
            a[i] -= v[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = 1e9;
        vector<int>a(k);
        solve(0, k, (int)cookies.size(), ans, cookies, a);
        return ans;
    }
};