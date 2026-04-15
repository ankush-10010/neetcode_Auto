class Solution {
public:
    int jump(vector<int>& nums) {
        // this is greedy question mostly
        // at each index we have to see where to
        /*int maxReach will be there , like for each index there should 
        be something that indicates what is its maxReach 
        there should be a counter which should count the minimum number 
        to reach the end
        for this to get we can also think of it in a way that we 
        will have an array for index , telling the minimum number of jumps to 
        reach there , but it will convert into a DP problem
        we also have to cater the problem of 0 , maybe it will be taken care of 
        by the previous approach*/

        /*as all indices in the same jump range share same jump count 
        so we should not think about dp , rather than this we should be 
        trying to process this with greedy*/

        /*
        the farthest index reachable within a certain window will be max(i+nums[i])
        */

        /*
        a variable that marks the end of the current jump window 
        a varibale that tracks the farthest reachable index seen so far
        a counter for number of jumps
        */

        int current_end = 0;
        int farthest = 0; //(max(i+nums[i]))

        int n = nums.size();
        int jumps = 0;

        for(int i=0;i<n-1;i++){
            farthest = max(farthest , i + nums[i]);

            if(i==current_end){
                jumps ++;
                current_end = farthest;
            }

        }
        return jumps;
    }
};
