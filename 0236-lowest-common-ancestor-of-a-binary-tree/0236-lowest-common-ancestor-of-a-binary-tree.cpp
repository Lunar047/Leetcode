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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)return root;
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left && right)return root;
        else if(!left)return right;
        else return left;

    }
    // void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m){
    //     if(!root)return;
    //     if(root->left){
    //         m[root->left] = root;
    //         parent(root->left,m);
    //     }
    //     if(root->right){
    //         m[root->right]=root;
    //         parent(root->right,m);
    //     }
    // }
     // Approach 01 using mapping of all parent nodes with their child node and
    // find the common parent in both of nodes parent list
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     // cout<<1<<" ";
    //     unordered_map<TreeNode*,TreeNode*> m,m1,m2;
    //     parent(root,m);
    //     m1[p] = m[p];
    //     p = m[p];
    //     m2[q] = m[q];
    //     q = m[q];
    //     // cout<<2<<" ";

    //     while(p!=q){
    //         if(m2.count(p)){
    //             return p;
    //         }
    //         if(m1.count(q)){
    //             return q;
    //         }
    //             m1[p] = m[p];
    //             p = m[p];
    //             m2[q] = m[q];
    //             q = m[q];
               
    //     }
    //     // cout<<3<<" ";

    //     return q;
    // }
};