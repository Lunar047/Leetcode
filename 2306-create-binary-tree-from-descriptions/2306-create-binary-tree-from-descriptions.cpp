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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> child,parent;
        for(auto &i:descriptions){
            int node_val = i[0],child_val = i[1],is_left = i[2];
            TreeNode *ptr;
            child.insert(child_val);
            if(!child.count(node_val))parent.insert(node_val);
            else parent.insert(node_val);
            
            if(mp.count(node_val))ptr = mp[node_val];
            else {
                ptr = new TreeNode(node_val);
                mp[node_val] = ptr;
            }
            if(is_left){
                if(mp.count(child_val)) ptr->left = mp[child_val];
                else {
                    ptr->left = new TreeNode(child_val);
                    mp[child_val] = ptr->left;
                }
            }
            else{
                if(mp.count(child_val))ptr->right = mp[child_val];
                else {
                    ptr->right = new TreeNode(child_val);
                    mp[child_val] = ptr->right;
                }
            }

        }
        for(auto &i:parent){
            if(!child.count(i))return mp[i];
        }
        return nullptr;
    }
};