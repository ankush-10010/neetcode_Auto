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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr) return {-1,-1};
        ListNode* temp = head;
        temp = head->next;
        if(temp->next == nullptr) return {-1,-1};
        vector<int> distances;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        while(curr->next != nullptr){
            if(curr->next->val < curr->val && prev->val < curr->val){
                distances.push_back(index);
            }
            if(curr->next->val > curr->val && prev->val > curr->val){
                distances.push_back(index);
            }
            index++;
            curr = curr->next;
            prev = prev->next;
        }
        
        if (distances.size() < 2) {
            return {-1, -1};
        }

        sort(distances.begin(),distances.end());
        for(int d : distances) cout << d << "\t";
        cout << endl;
        int maxDist = distances[distances.size() - 1] - distances[0];
        int minDist = INT_MAX;
        for(int i=1;i<distances.size();i++){
            int temp = distances[i] - distances[i-1];
            minDist = min(minDist,temp);
        }
        return {minDist,maxDist};
    }
};