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
    int findLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh) {
            // Perfect binary tree
            return (1 << lh) - 1;  // faster than pow(2, lh)
        }

        // Otherwise, recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
