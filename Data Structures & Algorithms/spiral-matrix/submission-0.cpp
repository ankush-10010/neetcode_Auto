class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        int srow = 0, erow = row - 1, scol = 0, ecol = col - 1;
        while(srow <= erow && scol <= ecol){
            for(int i = scol;i<=ecol;i++){
                result.push_back(matrix[srow][i]);
            }
            for(int i = srow+1;i<=erow;i++){
                result.push_back(matrix[i][ecol]);
            }
            if(srow < erow){
                for(int i = ecol - 1; i >= scol; i--){
                    result.push_back(matrix[erow][i]);
                }
            }
            if(scol < ecol){
                for(int i = erow - 1; i > srow; i--){
                    result.push_back(matrix[i][scol]);
                }
            }
            // update
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return result;
    }
};
