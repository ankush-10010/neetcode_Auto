class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int i,int j,int index){
        int row = board.size();
        int col = board[0].size();
        if(index == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=row || j>=col){
            return false;
        }
        if(board[i][j]!=word[index]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board,word,i+1,j,index+1) ||
                    dfs(board,word,i-1,j,index+1) ||
                    dfs(board,word,i,j+1,index+1) ||
                    dfs(board,word,i,j-1,index+1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // can get access to the characters using word[i]
        /* for any particular i,j in the board we will check the 
            elements of (i+1,j),(i,j+1),(i-1,j),(i,j-1)
        */
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
