class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxA=0;
        int maxB=0;
        int maxC=0;
        for(int i=0;i<triplets.size();i++){
            // for(int j=0;j<3;j++){
            //     if(triplets[i][j] > target[j]){
            //         continue;
            //     }
            // }
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
            }
            maxA = max(maxA,triplets[i][0]);
            maxB = max(maxB,triplets[i][1]);
            maxC = max(maxC,triplets[i][2]);
        }
        if(maxA == target[0] && maxB == target[1] && maxC == target[2]){
            return true;
        }
        return false;
    }
};
