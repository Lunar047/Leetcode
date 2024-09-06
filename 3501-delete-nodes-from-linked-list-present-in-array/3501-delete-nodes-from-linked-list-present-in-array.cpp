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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto &i:nums)mp[i]++;
        ListNode*ptr = head,*pre = nullptr;
        while(ptr){
            if(mp.count(ptr->val)){
                if(!pre || ptr ==head)head = head->next;
                else pre->next = ptr->next;
            }
            else pre = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};