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
 #include <queue>

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

struct CompareNode {
    bool operator()(const ListNode* lhs, const ListNode* rhs) const {
        return lhs->val > rhs->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode* ans=new ListNode;
        // if(lists.size()<1) return nullptr;
        // else if(lists.size()==1) return lists[0];
        // int l = 0;
        // ListNode* ptr,*p_ans;
        // p_ans=ans;
        // while(lists.size()>1)
        // {
        //  if(!lists[0])
        //   ptr = lists[0];
        //  for(int i =0;i<lists.size();i++)
        //  {
        //     if(lists[i]==nullptr)
        //     {
        //         lists.erase(lists.begin()+i);
        //     }
        //     else if(ptr==NULL) ptr= lists[i];
        //     else if(ptr->val>lists[i]->val)
        //     {
        //         ptr=lists[i];
        //         l=i;
        //     }
        //  }
        //  if(ptr==NULL) break;
        //  p_ans->next = ptr;
        //  p_ans=p_ans->next;
        //  lists[l]=lists[l]->next;
        // }
        // return ans;
        // gpt
           // Create a min heap to store the smallest nodes from each list
    std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> minHeap;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            minHeap.push(lists[i]);
        }
    }
    
    // Create a dummy node and a pointer to keep track of the merged list
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    
    // Pop the smallest node from the heap and add it to the merged list
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        curr->next = node;
        curr = curr->next;
        
        // Add the next node from the same list to the heap
        if (node->next) {
            minHeap.push(node->next);
        }
    }
    
    // Return the merged list
    return dummy->next;
  }

};