class DSU{
private: 
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x,int y){
        int leaderX = find(x);
        int leaderY = find(y);
        if(leaderX != leaderY){
            if(rank[leaderX] > rank[leaderY]){
                parent[leaderY] = leaderX;
            }else if(rank[leaderX] < rank[leaderY]){
                parent[leaderX] = leaderY;
            }else{
                parent[leaderY] = leaderX;
                rank[leaderX]++;
            }
        }
    }
    bool isConnected(int x,int y){
        return (find(x) == find(y));
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for(auto& pair: pairs){
            dsu.unite(pair[0],pair[1]);
        }
        unordered_map<int,vector<int>> leaders;
        for(int i=0;i<n;i++){
            int leaderI = dsu.find(i);
            leaders[leaderI].push_back(i);
        }

        string result = s;
        for(auto& [leader , indices] : leaders){
            string temp;
            for(int k=0;k<indices.size();k++){
                temp += s[indices[k]];
            }
            sort(temp.begin(),temp.end());
            for(int k=0;k<indices.size();k++){
                result[indices[k]] = temp[k];
            }            
        }

        return result;
    }
};