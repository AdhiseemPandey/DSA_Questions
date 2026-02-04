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
private : 
    TreeNode* buildPostInTree ( vector <int>& inorder,int is, int ie, vector<int>& postorder,int ps , int pe, map<int,int> &hashM ){
       if ( ps > pe || is > ie ) return NULL ; 
       TreeNode* root = new TreeNode ( postorder[pe] ) ;
       int inRoot = hashM [ postorder[pe]] ;
       int numsleft = inRoot - is ; 
       root->left = buildPostInTree( inorder,is , inRoot -1 , postorder, ps , ps + numsleft - 1, hashM);
       root->right = buildPostInTree( inorder,inRoot + 1  , ie , postorder, ps+numsleft , pe - 1, hashM);
       return root; 
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if ( inorder.size() != postorder.size() ) return NULL ; 
        map < int, int > hashM; 
        for ( int i = 0 ; i < inorder.size() ; i++ ) hashM[ inorder[i] ] = i ; 
        return buildPostInTree( inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1 , hashM ) ;
    }
};