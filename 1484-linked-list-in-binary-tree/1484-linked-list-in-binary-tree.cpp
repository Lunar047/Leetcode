/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(ListNode *head,TreeNode*root){
        if(!root)return 0;
        if(head->val== root->val){
            if(isSubPath(head,root,head))return 1;
        }
        return check(head,root->left) || check(head,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root,ListNode *H) {
        if(!head)return 1;
        else if(!root)return 0;
        if(root->val==head->val)return isSubPath(head->next,root->left,H) || isSubPath(head->next,root->right,H);
        else return 0;
        // return 1;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return check(head,root);
    }
};