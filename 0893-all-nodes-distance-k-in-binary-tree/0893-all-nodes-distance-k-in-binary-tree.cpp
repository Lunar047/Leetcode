/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool flag = false;
    void storeParent(TreeNode*root,TreeNode*&target,unordered_map<TreeNode*,TreeNode*> & parent){
        if(!root)return;
        // if(root->val==target->val)flag=true;
        if(root->left)
        {
            parent[root->left]=root;
            storeParent(root->left,target,parent);
        } 
        if(root->right)
        { 
            parent[root->right]=root;
            storeParent(root->right,target,parent);
        }
    }
    void solve(TreeNode* target,unordered_map<TreeNode*,TreeNode*> &parent,unordered_map<TreeNode*,int>& visited,vector<int>&ans,int &k,int current=0)
    {
        if(!target || current>k)return;
        if(visited.find(target)!=visited.end())return;
        if(current ==k){
            ans.push_back(target->val);
            return;
        }
        visited[target]=1;
        solve(target->left,parent,visited,ans,k,current+1);
        solve(target->right,parent,visited,ans,k,current+1);
        solve(parent[target],parent,visited,ans,k,current+1);
        

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root)return ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,int> visited;
        storeParent(root,target,parent);
        // if(!flag)return ans;
        solve(target,parent,visited,ans,k);
        return ans;
    }
};