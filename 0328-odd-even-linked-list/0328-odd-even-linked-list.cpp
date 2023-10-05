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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* ptr=head,*ptr2=head->next,*temp=head->next;
        while(ptr2 && ptr2->next){
            ListNode *t =ptr2->next;
            ptr->next = t;
            ptr2->next = t->next;
            ptr = t;
            ptr2=ptr2->next;
        }
        ptr->next = temp;
        return head;
    }
};