class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int reader = 1;
        int writer = 1;

        int n = nums.size();
        if (nums.empty()) {
            return 0;
        }

        while(reader<n && writer<n){
            if(nums[reader] == nums[reader-1]){
                //same element
                reader++;
            }else{
                //diff element
                nums[writer] = nums[reader];
                writer++;
                reader++;
            }
        }
        return writer;
    }
};