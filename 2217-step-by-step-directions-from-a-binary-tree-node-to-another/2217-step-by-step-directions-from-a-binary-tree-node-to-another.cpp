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
    TreeNode*LCA(TreeNode *root,int &start,int &end){
        if(!root)return nullptr;
        if(root->val==start || root->val==end)return root;
        TreeNode* left=nullptr,*right = nullptr;
        left = LCA(root->left,start,end);
        right = LCA(root->right,start,end);
        if(left && right)return root;
        else if(!left)return right;
        else return left;
    }
    void LCA_to_start(TreeNode *root,int &start,string &s,string &ans){
        if(!root)return;
        else if(root->val==start){
            ans += s;
            return;
        }
        s.push_back('U');
        LCA_to_start(root->left,start,s,ans);
        LCA_to_start(root->right,start,s,ans);
        s.pop_back();
        
    }
    void LCA_to_end(TreeNode *root,int &end,string &cur,string &ans){
        if(!root)return;
        else if(root->val==end){
            ans+=cur;
            return;
        }
        cur.push_back('L');
        LCA_to_end(root->left,end,cur,ans);
        cur.pop_back();
        cur.push_back('R');
        LCA_to_end(root->right,end,cur,ans);
        cur.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = LCA(root,startValue,destValue);
        string cur,ans;
        // cout<<lca->val<<" ";
        LCA_to_start(lca,startValue,cur,ans);
        // cout<<cur<<" "<<ans<<endl;
        // cur.clear();
        LCA_to_end(lca,destValue,cur,ans);
        return ans;
    }
};