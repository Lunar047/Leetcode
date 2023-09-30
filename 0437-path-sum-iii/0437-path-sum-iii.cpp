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
    void solve(TreeNode*root,int &k,int &ans,vector<int> &path){
        if(!root)return;
        path.push_back(root->val);
        if(root->left)solve(root->left,k,ans,path);
        if(root->right)solve(root->right,k,ans,path);
        long long sum =0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==k){
                ans++;
            }
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int ans =0;
        solve(root,targetSum,ans,path);
        return ans;
    }
};