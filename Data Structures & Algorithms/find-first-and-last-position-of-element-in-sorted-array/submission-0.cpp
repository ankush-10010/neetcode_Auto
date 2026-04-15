class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = -1;
        int ans2 = -1;
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans2 = mid;
                start = mid + 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        start = 0;
        end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans1 = mid;
                end = mid - 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        vector<int> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};