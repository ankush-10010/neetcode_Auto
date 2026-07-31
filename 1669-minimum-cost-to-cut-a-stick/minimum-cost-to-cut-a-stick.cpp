class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& memo){
        if(j-i == 1) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int minCost = INT_MAX;
        for(int k=i+1;k<j;k++){
            int cuttingCost = cuts[j] - cuts[i];
            int leftCost = solve(i,k,cuts,memo);
            int rightCost = solve(k,j,cuts,memo);
            minCost = min(minCost , cuttingCost + leftCost + rightCost);
        }
        return memo[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> memo(cuts.size()+2,vector<int>(cuts.size()+2,-1));
        vector<int> cuts1(cuts.size()+2);
        sort(cuts.begin(),cuts.end());
        cuts1[0] = 0;
        cuts1[cuts.size()+1] = n;
        for(int i=0;i<cuts.size();i++){
            cuts1[i+1] = cuts[i];
        }
        for(int cut : cuts1){
            cout << cut << "\t";
        }
        
        return solve(0,cuts.size()+1,cuts1,memo);
        // return 0;
    }
};