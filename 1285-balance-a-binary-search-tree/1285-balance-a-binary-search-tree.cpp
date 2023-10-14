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
    void inorder(TreeNode * root,vector<int> &arr){
        if(!root)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceTree(TreeNode*root,vector<int>&arr,int s ,int e){
        if(s>e)return nullptr;
        int mid = s+(e-s)/2;
        if(!root)root = new TreeNode(arr[mid]);
        else root->val = arr[mid];
        root->left = balanceTree(root->left,arr,s,mid-1);
        root->right = balanceTree(root->right,arr,mid+1,e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int n = arr.size();
        root = balanceTree(root,arr,0,n-1);
        return root;
    }
};