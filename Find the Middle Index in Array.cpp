
// Link Of Problem

// https://leetcode.com/problems/find-the-middle-index-in-array/

// 1991. Find the Middle Index in Array


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>sum(n + 1);
        for(int i = n - 1; i >= 0;i--){
            if(i == n - 1)sum[i] = nums[i];
            else sum[i] = sum[i + 1] + nums[i];
        }
        int cnt = 0;
        for(int i = 0 ; i < n;i++){
            cnt += nums[i];
            if(!i && !sum[1])return 0;
            else if(i && (cnt - nums[i]) == sum[i + 1])return i;
        }
        return -1;
    }
};