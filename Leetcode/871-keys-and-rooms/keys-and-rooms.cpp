class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        // for(int r: rooms[0]){
        //     q.push({r});
        // }
        vector<int> visited(rooms.size(),false);
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            // visited[room] = true;
            for(int neigh : rooms[room]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push(neigh);
                }
                // q.push(neigh);
            }
        }

        for(int i=0;i<rooms.size();i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};