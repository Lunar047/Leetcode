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
typedef long long ll;
class Solution {
private:
    bool isBST(TreeNode* root,ll low = LLONG_MIN,ll high = LLONG_MAX){
        if(!root)return 1;
        else if(( root->val<=low) || ( root->val>=high))return 0;
        else return isBST(root->left,low,root->val) && isBST(root->right,root->val,high);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))return 1;
        return isBST(root);
    }
    // bool isValidBST(TreeNode* root) {
    //     if(!root || (!root->left && !root->right))return 1;
    //     else if(!root->left || !root->right){
    //         if(!root->left){
    //             if(root->right->val<=root->val)return 0;
    //             else return isValidBST(root->right);
    //         }
    //         else{
    //             if(root->left->val>=root->val)return 0;
    //             else return isValidBST(root->left);
    //         }
    //     }
    //     else{
    //         if(root->left->val>=root->val || root->right->val<=root->val)return 0;
    //         else return isValidBST(root->left) && isValidBST(root->right);
    //     }
    // }
};