


// Link Of Problem

// https://leetcode.com/problems/minimize-maximum-of-array/

// 2439. Minimize Maximum of Array







class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = (int)nums.size();
        int l = 0, r = 1e9 + 10, mid = 0, ans = 0;
        while(l <= r){
            mid = (l + r) / 2;
            long long cnt = 0;
            bool ok = 1;
            for(int i = 0 ; i < n;i++){
                if(nums[i] > mid){
                    int x = nums[i] - mid;
                    if(cnt < x){
                        ok = 0;
                        break;
                    }
                    cnt -= x;
                }
                else cnt += (mid - nums[i]);
            }
            if(ok){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};