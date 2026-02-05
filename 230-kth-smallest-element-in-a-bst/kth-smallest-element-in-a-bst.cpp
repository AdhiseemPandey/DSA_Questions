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
    void traverse( TreeNode* node, int k, int &cnt, int & result ){
        if ( node == NULL ) return; 
        traverse( node -> left, k, cnt, result );
        cnt++;
        if ( cnt == k ){
            result = node -> val ;
            return ;
        }
        traverse( node -> right, k, cnt, result ) ; 
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0 ; 
        int result = 0; 
        traverse( root, k, cnt, result ) ;
        return result ; 
    }
};