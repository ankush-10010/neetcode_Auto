/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid,int row,int col,int length){
        int top_element = grid[row][col];
        int last_row = row + length;
        int last_col = col + length;
        bool isSame = true;
        for(int i=row;i<last_row;i++){
            for(int j=col;j<last_col;j++){
                if(grid[i][j] != top_element){
                    isSame = false;
                    break;
                }
            }
            if(!isSame){
                break;
            }
        }

        if(isSame == true){
            Node* newNode = new Node(top_element , true);
            return newNode;
        }else{
                int newLength = length/2;
                Node* parent = new Node(true,false);
                parent->topLeft=dfs(grid,row,col,newLength);
                parent->topRight=dfs(grid,row,col+newLength,newLength);
                parent->bottomLeft=dfs(grid,row+newLength,col,newLength);
                parent->bottomRight=dfs(grid,row+newLength,col  +newLength,newLength);
                return parent;
            }

    }
    Node* construct(vector<vector<int>>& grid) {
        int length = grid.size();
        return dfs(grid,0,0,length);
    }
};