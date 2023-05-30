
// Link Of Problem

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// 215. Kth Largest Element in an Array




class Solution {
    int frq[2*10004]{0};
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(auto &it: nums)frq[it + 10000]++;
        int ans = 0;
        for(int i = 20000;i >= 1;i--){
            if(k <= frq[i]){
                ans = i - 10000;
                break;
            }
            k -= frq[i];
        }
        return ans;
    }
};