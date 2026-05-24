class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());

        if(visited.count("0000")){
            return -1;
        }

        queue<string> q;
        q.push("0000");

        int turns = 0;

        while(!q.empty()){
            int levelsize = q.size();

            for(int i=0;i<levelsize;i++){
                string current = q.front();
                q.pop();

                if(current == target){
                    return turns;
                }

                for(int j=0;j<4;j++){
                    string up = current;
                    string down = current;

                    up[j] = (up[j] == '9') ? '0' : up[j] + 1;
                    down[j] = (down[j] == '0') ? '9' : down[j] - 1;

                    if(!visited.count(up)){
                        visited.insert(up);
                        q.push(up);
                    }

                    if(!visited.count(down)){
                        visited.insert(down);
                        q.push(down);
                    }

                }
            }
            turns++;
        }
        return -1;
    }
};