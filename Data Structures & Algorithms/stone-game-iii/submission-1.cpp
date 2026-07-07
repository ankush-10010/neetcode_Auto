class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> max_diff(n+1,0);

        for(int i=n-1;i>=0;i--){
            int take1 = -1e9;
            int take2 = -1e9;
            int take3 = -1e9;
            if(i <= n-1){
                take1 = stoneValue[i] - max_diff[i+1];
            }
            if(i <= n-2){
                take2 = stoneValue[i] + stoneValue[i+1] - max_diff[i+2];
            }
            if(i <= n-3){
                take3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - max_diff[i+3];
            }

            max_diff[i] = max(take1,max(take2,take3));
        }

        if(max_diff[0] == 0){
            return "Tie";
        }

        return (max_diff[0] > 0) ? "Alice" : "Bob";
    }
};