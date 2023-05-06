

// Link Of Problem

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// 1498. Number of Subsequences That Satisfy the Given Sum Condition






class Solution {
    int mod = 1e9 + 7;
    // Fast Power 
    long long fpow(long long n, long long x) {
    if (x == 0) {
        return 1;
    }
    if (x == 1) {
        return n % mod;
    }
    long long ans = fpow(n, x / 2) % mod;
    ans = (ans % mod) * (ans % mod) % mod;
    if (x & 1) {
        ans = (ans % mod) * (n % mod) % mod;
    }
    return ans;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size();i++){
            int x = target - nums[i];
            if(x < nums[i])break;
            int idx = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            cout << idx - i - 1 << endl;
            ans += fpow(2, idx - i - 1);
            ans %= mod;
        }
        return ans;
    }
};