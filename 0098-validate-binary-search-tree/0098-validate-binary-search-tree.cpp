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
    typedef long long ll;
    bool isBST(TreeNode* root,ll left,ll right){
        if(!root)return 1;
        if(root->val>left && root->val<right)return isBST(root->left,left,root->val) && isBST(root->right,root->val,right);;
        return 0;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))return 1;
        return isBST(root,LLONG_MIN,LLONG_MAX);
    }
};