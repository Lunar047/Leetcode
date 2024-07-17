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
    vector<TreeNode*> ans;
    void solve(TreeNode*root,TreeNode*parent,bool is_left,map<int,int> &to_delete){
        if(!root)return;
        if(!parent && !to_delete.count(root->val))ans.push_back(root);
        if(to_delete.count(root->val)){
            solve(root->left,nullptr,1,to_delete);
            solve(root->right,nullptr,0,to_delete);
            if(parent){
                if(is_left)parent->left = nullptr;
                else parent->right = nullptr;
            }
            root->left = nullptr;
            root->right = nullptr;
        }
        else{
            solve(root->left,root,1,to_delete);
            solve(root->right,root,0,to_delete);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int,int> delete_;
        for(auto &i:to_delete)delete_[i]++;
        solve(root,nullptr,0,delete_);
        return ans;
    }
};