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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
    
// private:
//     void inorder(TreeNode* node, vector<int>& result) {
//         if (node == nullptr) return;
//         inorder(node->left, result);      // Traverse left
//         result.push_back(node->val);      // Visit root
//         inorder(node->right, result);     // Traverse right
//     }
// };

// Morris Traversal 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Case 1: No left child, visit node
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                // Case 2: Has left child, find predecessor
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Make thread and move left
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Thread exists, remove it and visit node
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
