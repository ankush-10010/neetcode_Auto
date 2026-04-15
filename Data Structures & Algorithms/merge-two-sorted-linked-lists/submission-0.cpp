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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* resultHEAD=nullptr;
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        if(list1==nullptr && list2!=nullptr){
            return list2;
        }
        if(list2==nullptr && list1!=nullptr){
            return list1;
        }
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        ListNode *temp;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val <= temp2->val){
                if(resultHEAD==nullptr){
                    resultHEAD=temp1;
                    temp=resultHEAD;
                    temp1=temp1->next;
                }else{
                    temp->next=temp1;
                    temp1=temp1->next;
                    temp=temp->next;
                }
            }
            else{
                if(resultHEAD==nullptr){
                    resultHEAD=temp2;
                    temp=resultHEAD;
                    temp2=temp2->next;
                }else{
                    temp->next= temp2;
                    temp2=temp2->next;
                    temp=temp->next;
                }
            }
        }
        if(temp1!=nullptr){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }else{
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
        return resultHEAD;
    }
};
