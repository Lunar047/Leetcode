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
    void burnTree(TreeNode*& root)
    {
        if(root==nullptr) return;
        // cout << root->val << " ";
        burnTree(root->left);
        burnTree(root->right);
        // if(root->left)
        // delete root->left;
        // if(root->right)
        // // delete root->right;
        delete root;
        root=nullptr;
    }
    void preOrder(TreeNode*& root,vector<int> &ans)
    {
        if(!root) return;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    void flatten(TreeNode* root) {
        if(root==nullptr) return ;
        else if(root->left==nullptr && root->right==nullptr) return;
        // cout << "Hello" << endl;
        vector<int> ans;
        preOrder(root,ans);
        // cout << "Hello" << endl;
        // for(const auto& i : ans)
        //     cout << i << " ";
        // cout << endl;
        TreeNode *ptr=root;
          if(ptr!=nullptr)
          {
            burnTree(ptr->left);
            burnTree(ptr->right);
          }

        // burnTree(root->left);
        for(int i=1;i<ans.size();i++)
        {
                TreeNode * t = new TreeNode(ans[i]);
                ptr->right=t;
                ptr=ptr->right;
        }

    }
};