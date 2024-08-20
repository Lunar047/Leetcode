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
long long ans = 0,d;
vector<int> solve(TreeNode*root){
    if(!root)return {};
    if(!root->left && !root->right){
        return {0};
    }
    vector<int> left = solve(root->left);
    vector<int> right = solve(root->right);
    for(int i=0;i<left.size();i++){
        if(d>left[i]){
            int target = d - 1 - left[i];
            int it = lower_bound(right.begin(),right.end(),target)-right.begin();
            ans += it;
        }
        else break;
       
    }
    vector<int> temp;
    int i=0,j = 0;
    while(i<left.size() && j<right.size()){
        if(left[i]<right[j])temp.push_back(left[i++]+1);
        else temp.push_back(right[j++]+1);
    }
    while(i<left.size())temp.push_back(left[i++]+1);
    while(j<right.size())temp.push_back(right[j++]+1);
    return temp;
}
    
public:
    int countPairs(TreeNode* root, int distance) {
        d =distance;
        vector<int> t = solve(root);
        // for(auto &i:t)cout<<i<<" ";cout<<endl;
        return ans;
    }   
};