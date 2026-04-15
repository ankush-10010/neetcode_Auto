class Solution {
public:
    void dfsHelper(int i, int j, vector<vector<int>>& heights , vector<vector<bool>>& reachable){
        // we will reverse the logic as we are starting from the 
        // target node , water can flow from low to high , can also flow on same level
        int row = heights.size();
        int col = heights[0].size();
        reachable[i][j]=true;
        vector<pair<int,int>> paths;
        paths.push_back({i+1,j});
        paths.push_back({i-1,j});
        paths.push_back({i,j+1});
        paths.push_back({i,j-1});
        
        for(auto path : paths){
            int nx= path.first;
            int ny= path.second;
            if(nx<0 || ny<0 || nx>=row || ny>=col){
                continue;
            }
            if(reachable[nx][ny]){
                continue;
            }
            if(heights[nx][ny] >= heights[i][j]){
                dfsHelper(nx,ny,heights,reachable);
            }
        }
        //checked all the neighboring 4 nodes 
        //if none of them were <= then we just get out of the dfs loop
        //now what?
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> canReachAtlantic;
        vector<vector<int>> canReachPacific;
        vector<vector<int>> canReachBoth; //basically this will ne intersection
        int row = heights.size();
        int col = heights[0].size();
        //nodes that can reach atlantic will be 
        //those nodes that can reach (lastrow,i) or (i,lastcol) , i from 0 to row
        //so we have target nodes to be these 
        // we will start dfs from these target nodes
        vector<vector<bool>> reachable_atlantic(row,vector<bool>(col,false));
        //doing this for atlantic nodes first
        for(int j=0;j<col;j++){ // (lastrow,i)
            int i=row-1;
            dfsHelper(i,j,heights,reachable_atlantic);
            //the all trues that we get in this reacable_atlantic will be
            // able to reach the atlantic oceans . rest will be false
        }
        for(int i=0;i<row;i++){ //(i,lastcol)
            int j=col-1;
            dfsHelper(i,j,heights,reachable_atlantic);
        } //these two for loops are for atlantic 

        vector<vector<bool>> reachable_pacific(row,vector<bool>(col,false));
        for(int j=0;j<col;j++){ //(0,i)
            int i=0;
            dfsHelper(i,j,heights,reachable_pacific);
        }
        for(int i=0;i<row;i++){ //(i,0)
            int j=0;
            dfsHelper(i,j,heights,reachable_pacific);
        }
        // now we have all the nodes that cann reach to pacific in reachable_pacific
        vector<vector<int>> result;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(reachable_atlantic[i][j] && reachable_pacific[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;   
    }
};
