// Link of Problem

// https://leetcode.com/problems/binary-search/

// 704. Binary Search










class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = find(nums.begin(), nums.end(), target) - nums.begin();
        if(idx == (int)nums.size())idx = -1;
        return idx;
    }
};