

// Link of Problem

// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// 129. Sum Root to Leaf Numbers







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
public:
    int DFS(TreeNode* root, int sum){
        sum = sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) return sum;
        int ret = 0;
        if(root->left != nullptr) ret += DFS(root->left, sum);
        if(root->right != nullptr) ret += DFS(root->right, sum);
        return ret;
    }
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
};