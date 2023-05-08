
// Link Of Problem

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


// 108. Convert Sorted Array to Binary Search Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* Binary_Tree(vector<int>&nums, int l, int r){
        if(l > r)return nullptr;
        int mid = (l + r) / 2;
        TreeNode* subRoot = new TreeNode;
        subRoot->val = nums[mid];
        subRoot->left = Binary_Tree(nums, l, mid - 1);
        subRoot->right = Binary_Tree(nums, mid + 1, r);
        return subRoot;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        return Binary_Tree(nums, l, r);
    }
};