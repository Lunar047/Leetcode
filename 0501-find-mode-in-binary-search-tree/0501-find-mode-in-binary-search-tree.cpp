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
  void solve(TreeNode*root,unordered_map<int,int> &m,int &maxf){
      if(!root)return;
      m[root->val]++;
      if(maxf<m[root->val])maxf = m[root->val];
      solve(root->left,m,maxf);
      solve(root->right,m,maxf);
  }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        int maxf =0;
        vector<int> ans;
        solve(root,m,maxf);
        for(auto it:m){
            if(it.second==maxf)ans.push_back(it.first);
        }
        return ans;
    }
};