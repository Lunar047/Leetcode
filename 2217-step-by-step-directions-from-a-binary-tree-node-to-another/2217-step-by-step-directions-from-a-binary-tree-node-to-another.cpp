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
    string ans;
    map<int,TreeNode*> parent;
    set<int> vis;
    void dfs(TreeNode*root,TreeNode*&start,TreeNode*&end,int &sv,int &ev){
        if(!root)return;
        // vis[root] = 0;
        if(root->val==sv)start = root;
        else if(root->val==ev)end = root;
        if(root->left){
            parent[root->left->val] = root;
            dfs(root->left,start,end,sv,ev);
        }
        if(root->right){
            parent[root->right->val] = root;
            dfs(root->right,start,end,sv,ev);
        }
    }
    void bfs(TreeNode *root,int end,string &ans,string &cur){
        if(!root)return;
        // vis[root] =1;
        vis.insert(root->val);
        if(root->val==end){
            ans = cur;
            return;
        }
        if(root->left && !vis.count(root->left->val)){
            cur.push_back('L');
            bfs(root->left,end,ans,cur);
            cur.pop_back();
        }
        if(root->right && !vis.count(root->right->val)){
            cur.push_back('R');
            bfs(root->right,end,ans,cur);
            cur.pop_back();
        }
        if(parent[root->val] && !vis.count(parent[root->val]->val)){
            cur.push_back('U');
            bfs(parent[root->val],end,ans,cur);
            cur.pop_back();
        }
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode*start,*end;
        parent[root->val] = nullptr;
        // vis[nullptr] = 1;
        dfs(root,start,end,startValue,destValue);
        string ans,cur;
        bfs(start,destValue,ans,cur);
        return ans;
    }
};