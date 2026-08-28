class Solution {
public:
    int partition(vector<int>& arr,int i,int j,vector<vector<int>>& memo){
        if(j-i == 0) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int minCost = INT_MAX;
        for(int k=i;k<j;k++){
            int maxLeft = *max_element(arr.begin()+i,arr.begin()+k+1);
            int maxRight = *max_element(arr.begin()+k+1,arr.begin()+j+1);
            int cost = maxLeft*maxRight;
            int leftCost = partition(arr,i,k,memo);
            int rightCost = partition(arr,k+1,j,memo);

            minCost = min(minCost,cost + leftCost + rightCost);
        }
        return memo[i][j] = minCost;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> memo(arr.size(),vector<int>(arr.size(),-1));
        return partition(arr,0,arr.size()-1,memo);
    }
};