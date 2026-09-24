class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sI = INT_MAX; 
        for(int i=0;i<nums.size();i++){
            int currNum = nums[i];
            int temp = currNum;
            int currSum = 0;
            while(temp != 0){
                currSum += temp%10;
                temp = temp/10;
            }
            if(currSum == i){
                sI = min(sI,i);
            }
        }

        return (sI == INT_MAX) ? -1 : sI;
        
    }
};