

// Link Of Problem

// https://leetcode.com/problems/number-of-zero-filled-subarrays/

// 2348. Number of Zero-Filled Subarrays







class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int l = 0 , r = 0;
        int n = (int)nums.size();
        while(l < n){
            while(r < n){
                if(nums[r] != 0)break;
                r++;
            }
            long long res = r - l;
            ans += (res * (res + 1) / 2);
            if(r == l){
                ++r, ++l;
            }
            else l = r;
        }
        return ans;
    }
};