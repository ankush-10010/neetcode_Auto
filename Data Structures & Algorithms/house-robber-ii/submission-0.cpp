class Solution {
public:
    int robLinear(vector<int>& nums, int l,int r){
        int prev2 = 0;
        int prev1 = 0;
        for(int i=l;i<=r;i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // we cannt rob two consecutive houses
        /* defining neighbour 
            for i = k 
            if(k==0) then neighbour is n-1 and 1
            if(k==n-1) then neighbour is n-2 and 0
            else neighbour is k-1 and k+1
        */
        // how do i make sure that i do not rob consecutive houses
        // we can make a n+1 dp array , where ith index shows maximum possible sum robber till the ith house
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        return max(
            robLinear(nums,0,n-2),
            robLinear(nums,1,n-1)
        );
    }
};
