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
    int solve(TreeNode*root,TreeNode*parent){
        if(!root)return 0;
        int ans = 0;
        ans+= solve(root->left,root);
        ans+= solve(root->right,root);
        if((root->left && root->left->val==0) || (root->right && root->right->val==0)){
            root->val = 1;
            ans++;
        }
        else if((root->left && root->left->val==1) || (root->right && root->right->val==1)){
            root->val = 2;
        }
        if(!parent && !root->val){
            ans++;
        }
        return ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        // else if(!root->left && !root->right)return 1;
        // return solve(1,1,root);
        return solve(root,nullptr);
    }
};