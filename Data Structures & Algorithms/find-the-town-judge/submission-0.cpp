class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }

        vector<int> trustScores(n+1,0);

        for(const auto& relation:trust){
            int a = relation[0];
            int b = relation[1];

            trustScores[a]--;
            trustScores[b]++;
        }

        for(int i=1;i<=n;i++){
            if(trustScores[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};