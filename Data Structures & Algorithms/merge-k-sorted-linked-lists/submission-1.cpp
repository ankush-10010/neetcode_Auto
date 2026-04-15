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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* temp1= l1;
        ListNode* temp2= l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        // ListNode* temp3= merged;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val > temp2->val){
                tail->next= temp2;
                temp2=temp2->next;
                tail=tail->next;
            }else{
                tail->next= temp1;
                temp1=temp1->next;
                tail=tail->next;
            }
        }
        if(temp1!=nullptr){
            tail->next =  temp1;
        }

        if(temp2!=nullptr){
            tail->next = temp2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode *result = lists[0];
        for(int i=1;i<lists.size();i++){
            result = mergeTwoLists(result , lists[i]);
        }
        return result;
    }
};
