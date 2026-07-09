class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> efforts(rows,vector<int>(cols,INT_MAX));

        auto cmp = [](const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b){
            return a.first > b.first; // the one with higehr value has less priorit
        };

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);
        // bascically created a min heap

        efforts[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int current_effort = it.first;
            int current_x = it.second.first;
            int current_y = it.second.second;

            if(current_x == rows-1 && current_y == cols-1){
                return current_effort;
            }

            if(current_effort > efforts[current_x][current_y]){
                continue;
            }

            for(int i=0;i<4;i++){
                int new_x = current_x + dx[i];
                int new_y = current_y + dy[i];

                if(new_x>=0 && new_x < rows && new_y >= 0 && new_y < cols){
                    int new_cost = abs(heights[new_x][new_y] - heights[current_x][current_y]);
                    int new_effort = max(current_effort, new_cost);

                    if(new_effort < efforts[new_x][new_y]){
                        efforts[new_x][new_y] = new_effort;
                        pq.push({new_effort,{new_x,new_y}});
                    }
                }
            }
        }
        return 0;
    }
};
