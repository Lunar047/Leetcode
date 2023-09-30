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
int ans =0;
    void preorder(TreeNode*root,int &k){
        if(!root || !k)return;
        preorder(root->left,k);
        k--;
        if(k==0)ans = root->val;
        preorder(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        preorder(root,k);
        return ans;
    }
    // void traverse(TreeNode*root,vector<int> &ans){
    //     if(!root)return;
    //     ans.push_back(root->val);
    //     traverse(root->left,ans);
    //     traverse(root->right,ans);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> temp;
    //     traverse(root,temp);
    //     priority_queue<int> pq;
    //     for(int i=0;i<k;i++){
    //         pq.push(temp[i]);
    //     }
    //     for(int i=k;i<temp.size();i++){
    //         if(pq.top()>temp[i]){
    //             pq.pop();
    //             pq.push(temp[i]);
    //         }
    //     }
    //     return pq.top();
    // }
};