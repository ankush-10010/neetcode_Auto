class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int union1(int x,int y){
        int leaderX = find(x);
        int leaderY = find(y);

        if(leaderX != leaderY){
            if(leaderX < leaderY){
                parent[leaderY] = leaderX;
                return leaderX;
            }else{
                parent[leaderX] = leaderY;
                return leaderY;
            } 
        }
        return leaderX;
    }
    void backtrack(int i,vector<vector<int>>& graph,vector<int>& current,vector<vector<int>>& result){
        if(i == graph.size() - 1){
            result.push_back(current);
        }
        for(int neigh : graph[i]){
            current.push_back(neigh);
            backtrack(neigh,graph,current,result);
            current.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        parent.resize(graph.size());
        vector<vector<int>> result;
        
        for(int i=0;i<graph.size();i++){
            parent[i] = i;
        }
        for(int i=0;i<graph.size();i++){
            for(int neigh : graph[i]){
                parent[neigh] = i;
                union1(neigh,i);
            }
        } 
        vector<int> current;
        
        current.push_back(0);
        backtrack(0,graph,current,result);
        // current.pop  _back();

        for(const auto& r: result){
            for(int i=0;i<r.size();i++){
                cout << r[i] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        return result;
    }
};