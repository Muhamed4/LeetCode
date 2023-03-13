

// Link of Problem

// https://leetcode.com/problems/symmetric-tree/

// 101. Symmetric Tree






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
    bool isSymmetric(TreeNode* root) {
        DFS(root->left);
        TreeNode* cop1 = root->left;
        TreeNode* cop2 = root->right;
        return isEqual(cop1, cop2);
    }
    void DFS(TreeNode* cop){
        if(cop == nullptr)return;
        TreeNode* temp = cop->left;
        cop->left = cop->right;
        cop->right = temp;
        DFS(cop->left);
        DFS(cop->right);
    }
    bool isEqual(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)return true;
        if(left == nullptr || right == nullptr || left->val != right->val)return false;
        bool flag = true;
        flag &= isEqual(left->left, right->left);
        flag &= isEqual(left->right, right->right);
        return flag;
    }
};