
// Link of Problem

// https://leetcode.com/problems/reducing-dishes/

// 1402. Reducing Dishes










class Solution {
    int dp[555][555];
    int sol(int idx, int cnt, vector<int>&v){
        if(idx == (int)v.size())return 0;
        int &ret = dp[idx][cnt];
        if(~ret)return ret;
        ret = 0;
        ret = max(ret, sol(idx + 1, cnt, v));
        ret = max(ret, sol(idx + 1, cnt + 1, v) + v[idx] * cnt);
        return ret;
    }
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        return sol(0, 1, v);
    }
};