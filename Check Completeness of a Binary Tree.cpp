

// Link of Problem

// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// 958. Check Completeness of a Binary Tree







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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(bfs.front() != nullptr){
            TreeNode* node = bfs.front();
            bfs.pop();
            bfs.push(node->left);
            bfs.push(node->right);
        }
        while(!bfs.empty()){
            if(bfs.front() != nullptr)return false;
            bfs.pop();
        }
        return true;
    }
};