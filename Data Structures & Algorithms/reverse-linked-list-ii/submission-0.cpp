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
        while(curr != tail){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       //we need two pointers , one will be at the left index 
       // second will be at the right index 
        ListNode* temp_left = head;
        ListNode* temp_right = head;
        ListNode* temp_left_before = head;
        for(int i=1;i<left-1;i++){
            temp_left_before = temp_left_before->next;
        }
        for(int i=1;i<left;i++){
            temp_left = temp_left->next;
        }
        for(int i=1;i<right+1;i++){
            temp_right = temp_right->next;
        }
        if(left == 1){
            head = reverse(temp_left,temp_right);
            temp_left->next = temp_right;
        }else{
            temp_left_before->next = reverse(temp_left,temp_right);
            temp_left->next = temp_right;
        }
        return head;
    }
};