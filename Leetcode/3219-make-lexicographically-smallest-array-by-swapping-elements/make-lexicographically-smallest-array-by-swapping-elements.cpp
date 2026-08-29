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
            }else if(rank[leaderY] > rank[leaderX]){
                parent[leaderX] = leaderY;
            }else{
                parent[leaderY] = leaderX;
                rank[leaderX]++;
            }
        }
    }

    bool connected(int x,int y){
        return (find(x) == find(y));
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> pairNums(nums.size());
        DSU dsu(nums.size());
        for(int i=0;i<nums.size();i++){
            pairNums[i] = {i,nums[i]};
        }
        auto cmp = [](const pair<int,int>& a,const pair<int,int>& b){
            return a.second < b.second;
        };
        sort(pairNums.begin(),pairNums.end(),cmp);
        vector<vector<int>> adj(nums.size());
        vector<pair<int,int>> indexLimitV(nums.size());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int currElement = pairNums[i].second;
            int nextElement = pairNums[i+1].second;
            if(nextElement - currElement <= limit){
                dsu.unite(pairNums[i].first,pairNums[i+1].first);
            }
        }
        unordered_map<int,vector<int>> leader; // mp[leader] --> [,,,,]
        for(int i=0;i<n;i++){
            int leaderI = dsu.find(i);
            leader[leaderI].push_back(i);
        }

        for(auto& [ldr,children] : leader){
            cout << format("[{}] ---> " , ldr);
            cout << "[" ;
            for(int child : children){
                cout << format("{} , ",child)<<"\t"; 
            }
            cout << "]";
            cout << endl;
        }

        vector<int> result(n);
        for(auto& [ldr,indices] : leader){
            vector<int> temp;
            for(int index : indices){
                temp.push_back(nums[index]);
            }
            sort(temp.begin(),temp.end());
            for(int k=0;k<indices.size();k++){
                result[indices[k]] = temp[k];
            }
        }
        return result;
    }
};