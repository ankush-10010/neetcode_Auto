class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        // deque has operations push_back,pop_back,front,back,pop_front
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
    // deque will be storing indices of the numbers instead of the number itself 
};
