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
bool isSame(TreeNode* left, TreeNode* right) {
        
        if(!left && !right) return true;
     if ((left==nullptr && right != nullptr) || (left!=nullptr && right == nullptr)||(left->val!=right->val) ) return false;
        if(left->val==right->val)   return (isSame(left->right,right->left) && isSame(left->left,right->right)); 
     return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSame(root->left,root->right);
        
    }
};