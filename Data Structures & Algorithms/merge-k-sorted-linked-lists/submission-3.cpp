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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        // interval dictates the gap between the two lists we are merging
        int interval = 1; 
        
        while (interval < lists.size()) {
            // Jump by interval * 2 to pair lists up correctly
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                // Merge the two lists and store the result back in the first slot
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            // Double the interval for the next pass
            interval *= 2; 
        }
        
        // The fully merged list will eventually end up at index 0
        return lists[0];
    }

private:
    // Standard helper function to merge exactly two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Dummy node acts as the starting point to easily build the new list
        // ListNode dummy;
        // ListNode* tail = &dummy;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        ListNode* dummy = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        
        // Attach whatever is left over
        if (l1 != nullptr) {
            dummy->next = l1;
        } else {
            dummy->next = l2;
        }
        
        return head;
    }
};