class Solution {
public:
    int findMin(vector<int> &nums) {
        int start=0;
        int cut;
        int end=nums.size()-1;
        int min_num=INT_MAX;
        for(int i=end;i>=0;i--){
            if(nums[i]>min_num){
                cut=i;
            }
            if(nums[i]<min_num){
                min_num=min(min_num,nums[i]);
            }
        }
        int ans;
        ans=min(nums[start], min_num);
        // while(start<=cut){
        //     int mid=start+(cut-start)/2;
        //     if(nums[mid]==)
        // }
        // int next_start=cut+1;
        // while(next_start<=end){

        // }
        return ans;
    }
};
