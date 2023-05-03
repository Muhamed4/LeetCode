
// Link Of Problem

// https://leetcode.com/problems/find-the-difference-of-two-arrays/

// 2215. Find the Difference of Two Arrays



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        map<int,int>mp1, mp2;
        for(auto &it: nums1)mp1[it]++;
        for(auto &it: nums2)mp2[it]++;
        for(auto &it : mp1){
            if(!mp2.count(it.first))ans[0].push_back(it.first);
        }
        for(auto &it: mp2){
            if(!mp1.count(it.first))ans[1].push_back(it.first);
        }
        return ans;
    }
};