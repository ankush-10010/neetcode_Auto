class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // how do you know that its not a dp question? 
        // circular sum = total sum - minimum sum
        int total = 0;
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int currMin = 0;
        int currMax = 0;
        bool allNegative = true;
        for(int num : nums){
            cout << num << "\t";
            total += num;
            currMax = max(currMax + num , num);
            currMin = min(currMin + num , num);
            minSum = min(minSum , currMin);
            maxSum = max(maxSum , currMax);
            if(num > 0) allNegative = false;
        }
        if(allNegative){
            return maxSum; 
        }
        return max(maxSum , total - minSum);
    }
};