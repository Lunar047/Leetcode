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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> parent;
        parent.push(root);
        ans.push_back(root->val);
        // Using Null as a separator between the levels so that we use only one queue and avoid extra spaces
        parent.push(NULL);
        while(parent.size()){
            TreeNode* t = parent.front();
            parent.pop();
            if(t==NULL){
                if(parent.size()){
                    t = parent.front();
                    ans.push_back(t->val);
                    parent.push(NULL);
                }
                else break;
            }
            if(t->right)parent.push(t->right);
            if(t->left)parent.push(t->left);
        }
        return ans;
    }
};