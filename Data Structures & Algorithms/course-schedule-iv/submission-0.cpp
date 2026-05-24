class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre:prerequisites){
            int u = pre[0];
            int v = pre[1];
            adj[u].push_back(v); //course u is prereq for course v
        }

        vector<vector<bool>> isReachable(numCourses,vector<bool>(numCourses,false));

        for(int i=0;i<numCourses;i++){
            queue<int>q;
            q.push(i);

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int neighbor : adj[curr]){
                    if(!isReachable[i][neighbor]){
                        isReachable[i][neighbor]=true;
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<bool> answer;
        for(const auto &query : queries){
            int u = query[0];
            int v = query[1];

            answer.push_back(isReachable[u][v]);
        }

        return answer;
    }
};