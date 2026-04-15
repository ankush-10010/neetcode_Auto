class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // vector<vector<bool>> isZero(row,vector<bool>(col,false));
        vector<bool> rowZero(row,false);
        vector<bool> colZero(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    // isZero[i][j] = true; // matrix[i][] = 0, matrix[][j] = 0
                    rowZero[i]=true;
                    colZero[j]=true;
                }
            }
        }
        for(int i=0;i<col;i++){
            if(colZero[i]){
                for(int k=0;k<row;k++){
                    matrix[k][i]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            if(rowZero[i]){
                for(int k=0;k<col;k++){
                    matrix[i][k]=0;
                }
            }
        }
    }
};
