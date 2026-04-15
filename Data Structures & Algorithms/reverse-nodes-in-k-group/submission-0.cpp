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
    ListNode* reverse(ListNode* head,ListNode* tail){
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!= tail){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
            return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // we will iterate for k-1 time now if k-1thNode-->next == nullptr
        // then we wont do anything otherwise 
        // if -->next != nullptr , then we will start with reversing 
        // for this we will make a function named as reverse node
        ListNode* tail = head;
        for(int i=0;i<k;i++){
            if(tail == nullptr){
                return head;
            }
            // head->next = reverseKGroup(head,i);
            tail=tail->next;
        }   
        ListNode* newHead = reverse(head,tail);
        head->next = reverseKGroup(tail,k);
        return newHead;
    }
};
