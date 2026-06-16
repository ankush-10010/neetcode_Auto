class NumMatrix {
private:
    vector<vector<int>>prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix = vector<vector<int>>(rows+1,vector<int>(cols+1,0));

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                prefix[r+1][c+1] = matrix[r][c] + 
                                    prefix[r][c+1]+
                                    prefix[r+1][c] -
                                    prefix[r][c];
                                    
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1+1;
        int c1 = col1+1;
        int r2 = row2+1;
        int c2 = col2+1;

        return prefix[r2][c2] 
                -prefix[r1-1][c2]
                -prefix[r2][c1-1]
                +prefix[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */