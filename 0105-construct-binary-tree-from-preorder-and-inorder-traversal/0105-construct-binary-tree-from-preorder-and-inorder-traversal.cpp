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
 // Try this problem again using mapping of inorder traversal index
class Solution {
public:
  bool isIn(vector<int>& a, int s,int e,int t)
  {
    for(int i=s;i<=e;i++)
    if(a[i]==t)return true;
    return false;
  }
  int search(vector<int>&In,int s,int e,int t)
  {
      for(int i=s;i<=e;i++)
      {
          if(In[i]==t) return i;
      }
      return -1;
  }
   TreeNode * BT(vector<int>&In,int s,int e, vector<int>&pre,int pos)
   {
       if(s>e)return nullptr;
       int p =0;
       for(int i =pos;i<pre.size();i++)
       {
           if(isIn(In,s,e,pre[i]))
           {
               p =i;
               break;
           }
       }
       TreeNode* root = new TreeNode(pre[p]);
       int m = search(In,s,e,pre[p]);
       if(m!=-1)
       {
      root->left = BT(In,s,m-1,pre,pos+1);
      root->right =  BT(In,m+1,e,pre,pos+1);
       }
       return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        root = BT(inorder,0,inorder.size()-1,preorder,0);
        return root;
    }
};