class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n+1,INT_MIN);
        vector<int> sold(n+1,0);
        vector<int> rest(n+1,0);
        hold[0] = INT_MIN;
        rest[0] = 0;
        sold[0] = 0;

        hold[1] = -prices[0];
        sold[1] = INT_MIN;
        rest[1] = 0;

        for(int i=2; i<n+1;i++){
            hold[i] = max(hold[i-1],rest[i-1]-prices[i-1]);
            sold[i] = hold[i-1] + prices[i-1];
            rest[i] = max(rest[i-1],sold[i-1]);
        }

        return max(sold[n],rest[n]);
    }
};
