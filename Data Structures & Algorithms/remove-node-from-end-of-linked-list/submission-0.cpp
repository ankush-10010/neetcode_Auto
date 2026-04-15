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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp= head;
        int m=0;
        ListNode* newTemp=head;
        while(newTemp!=nullptr){
            newTemp=newTemp->next;
            m++;
        }
        if(m==1 && n==1){
            return nullptr;
        }
        if(n==m){
            head=head->next;
            return head;
        }
        for(int i=0;i<m-n-1;i++){
            temp=temp->next;
        }
        ListNode* temp2=temp->next;
        temp->next=temp->next->next;
        temp2->next=nullptr;
        // delete temp2;
        return head;
    }
};
