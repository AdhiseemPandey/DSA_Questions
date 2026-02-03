/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Method 1 - 



// Method 2 - Without using extra space 

class Solution {
public:
    vector<int> ans;

    void down(TreeNode* target,int k){
        if(!target)return;
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        down(target->left,k-1);
        down(target->right,k-1);
    }

    bool up(TreeNode* root,TreeNode* target,int &k){
        if(!root)return false;
        if(root==target)return true;
        
        if(up(root->left,target,k)){
            k--;
            if(k==0)ans.push_back(root->val);
            down(root->right,k-1);
            return true;
        }

        if(up(root->right,target,k)){
            k--;
            if(k==0)ans.push_back(root->val);
            down(root->left,k-1);
            return true;
        }

        return false;

    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        down(target,k);
        up(root,target,k);
        return ans;
    }   
};








// +1 -1  Method 3 
// void tar(Node* root, int k, vector<int>&ans){
//         if(!root)return;
//         if(k == 0){
//             ans.push_back(root -> data);
//             return;
//         }
//         tar(root -> left, k - 1, ans);
//         tar(root -> right, k - 1, ans);
//     }
//     int fxn(Node* root, int target, int k, int val, vector<int>&ans){
//         if(!root)return -1;
//         if(root -> data == target){
//             tar(root, k, ans);
//             return k - 1;
//         }
//         if(val >= 0){
//             if(val == 0)ans.push_back(root -> data);
//             else{
//                 fxn(root -> left, target, k, val - 1, ans);
//                 fxn(root -> right, target, k, val - 1, ans);
//                 return -1;
//             }
//             return -1;
//         }
//         int left = fxn(root -> left, target, k, val, ans);
//         if(left >= 0){
//             if(left == 0){
//                 ans.push_back(root -> data);
//                 return -1;
//             }else{
//                 fxn(root -> right, target, k, left - 1, ans);
//                 return left - 1;
//             }
//         }
//         int right = fxn(root -> right, target, k, val, ans);
//         if(right >= 0){
//             if(right == 0){
//                 ans.push_back(root -> data);
//                 return -1;
//             }else{
//                 fxn(root -> left, target, k, right - 1, ans);
//                 return right - 1;
//             }
//         }
//         return -1;
//     }
//     vector<int> KDistanceNodes(Node* root, int target, int k) {
//         // return the sorted vector of all nodes at k dist
//         vector<int>ans;
//         fxn(root, target, k, -1, ans);
//         sort(ans.begin(), ans.end());
//         return ans;
//     }