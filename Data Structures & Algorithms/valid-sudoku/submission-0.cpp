class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char val = board[i][j];
                if(val == '.'){
                    continue;
                }else{
                    int x = i/3;
                    int y = j/3;
                    int m = 3*x+y;
                    if(rows[i].find(val) != rows[i].end() ||
                        cols[j].find(val) != cols[j].end() ||
                        boxes[m].find(val) != boxes[m].end()){
                            return false;
                        }
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[m].insert(val);
                }
            }
        }
        return true;
    }
};
/* give every col and every row its own hashmap to map its values 
in this way we will be able to know if a particular value exists in 
one row or one column */

