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
    void solve(queue<TreeNode*> &cur,queue<TreeNode*> &chi,vector<int> &o,vector<vector<int>> &ans)
    {
        if(cur.size()<1) return ;
        while(cur.size())
        {
            TreeNode* t = cur.front();
            if(t)
            {
                o.push_back(t->val);
                chi.push(t->left);
                chi.push(t->right);
            }
          cur.pop();
        }
        //  reverse(o.begin(),o.end());
          if(o.size()>0)
            ans.push_back(o);
            o.clear();
            solve(chi,cur,o,ans);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       vector<int> o;
       queue<TreeNode*> current;
       queue<TreeNode*> child;
       if(!root) return ans;
       current.push(root);
       solve(current,child,o,ans); 
       return ans;
    }
};