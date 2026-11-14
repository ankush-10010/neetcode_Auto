class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq; // number , count

        long long totalSubarrays = 0;
        long long currentCost = 0;
        int right = n-1;
        for(int left=n-1;left>=0;left--){
            long long currentCount = 1;

            while(!dq.empty() && dq.front().first < nums[left]){
                long long diff = (nums[left] - dq.front().first);
                currentCost += diff*dq.front().second;
                currentCount += dq.front().second;

                dq.pop_front();
            }
            dq.push_front({nums[left],currentCount});

            while(currentCost > k){
                long long rightMaxRunning = dq.back().first; 
                currentCost -= (rightMaxRunning - nums[right]);
                dq.back().second--;
                if(dq.back().second == 0) dq.pop_back();
                right--;
            }

            totalSubarrays += (right - left + 1);
        }
        return totalSubarrays;
    }
};