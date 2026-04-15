class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> temp2(prices.size(),0);

        int n = prices.size();
        int leftptr = 0;
        
        while(leftptr <= n-1){
            int rightptr = n-1;
            while(leftptr<rightptr){
                if(prices[leftptr] < prices[rightptr]){
                temp2[leftptr] = max(prices[rightptr]-prices[leftptr] , temp2[leftptr]);
                }else{
                    temp2[leftptr] = max(0,temp2[leftptr]);
                }
                rightptr--;
            }
            leftptr++;
        }
        sort(temp2.begin(),temp2.end());
        return temp2[n-1];
    }
};
