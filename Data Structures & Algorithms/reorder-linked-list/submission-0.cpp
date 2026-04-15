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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        ListNode* curr=head;
        if(curr==nullptr){
            return nullptr;
        }
        while(curr->next!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        curr->next=prev;
        prev=curr;
        head = prev;
        return head;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow ans fast are at middle of the list
        ListNode* second=reverseList(slow->next);
        slow->next=nullptr;
        //now we have two lists 
        ListNode *first=head;
        while(second!=nullptr){
            ListNode *t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;
            first=t1;
            second=t2;  
        }
    }
};
