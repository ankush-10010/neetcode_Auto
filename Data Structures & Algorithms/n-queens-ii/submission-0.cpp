class Solution {
public:
    bool safe(vector<string>& board,int i,int j,int n){
        int temp_i = i;
        int temp_j = j;
        while(temp_i>0){
            if(board[temp_i-1][temp_j] != '.'){
                return false; //vertical not safe
            }
            temp_i--;
        }
        temp_i = i;
        temp_j = j;
        while(temp_i>0 && temp_j>0){
            if(board[temp_i-1][temp_j-1] != '.'){
                return false; // left up not safe
            }
            temp_i--;
            temp_j--;
        }
        temp_i = i;
        temp_j = j;
        while(temp_i>0 && temp_j<n-1){
            if(board[temp_i-1][temp_j+1] != '.'){
                return false;
            }
            temp_i--;
            temp_j++;
        }
        return true;
    }
    void solve(int row,int n,vector<string>& board,vector<vector<string>>& result){
        if(row==n){
            result.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(safe(board,row,j,n)){
                board[row][j] = 'Q';
                solve(row+1,n,board,result);
                board[row][j] = '.';
            }
            //dfs basics are that we remove the thing we did earlier and move forward with other options
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result; // board will be appended to result as we move on
        solve(0,n,board,result);
        return result.size();
    }
};
