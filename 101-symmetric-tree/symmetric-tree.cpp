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
private: 
    bool isSymHelp(TreeNode* left, TreeNode* right) {

        if (left == nullptr || right == nullptr) 
            return left == right;  

        if (left->val != right->val) 
            return false;

        return isSymHelp(left->left, right->right) && 
               isSymHelp(left->right, right->left);
               
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymHelp(root->left, root->right);
    }
};