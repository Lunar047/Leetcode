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
//  ListNode* reverseKGroup(ListNode* head, int k) {
//       if(head==NULL || head->next==NULL) return head;
//       // try{
//         int c = 0;
//         ListNode * ptr = head, *preptr = nullptr,*pre2 = nullptr;
//         while(ptr)
//         {
//           ptr=ptr->next;
//           c++;
//           if(c>=k) break;
//         }
//         if(c<k) return head;
//         else
//         {
//           c=0;
//           ptr = head;
//         }
//         while(c<k && ptr)
//         {
//           pre2 = ptr->next;
//           ptr->next = preptr;
//           preptr = ptr;
//           ptr = pre2;
//           c++;
//         }
//         if(pre2)
//         head->next = reverseKGroup(pre2,k);
//       // }catch()
//         return preptr;
//     }
    ListNode * swap(ListNode* head)
    {
        if(head == NULL || !head->next) return head;
        ListNode * ptr = head->next;
        head->next = swap(ptr->next);
        ptr->next = head;
        return ptr;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        // ListNode* ptr = head,*nxt1 ,*nxt = ptr->next;
        // nxt1 = nxt->next;
        // nxt->next = ptr;
        // cout<<"ptr "<<ptr->val<<" nxt  "<<nxt->val<<endl;
        // ptr->next = swapPairs(nxt1);
        head = swap(head);
        return head;
        // Method 02
        // return reverseKGroup(head,2);
    }
};