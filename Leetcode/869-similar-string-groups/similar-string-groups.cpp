class Solution {
public:
    vector<int> parent;
    int groupCount;
    int findParent(int x){
        if(parent[x] == x) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void union1(int x, int y){
        int leaderX = findParent(x);
        int leaderY = findParent(y);
        if(leaderX != leaderY){
            parent[leaderX] = leaderY;
            groupCount--;
        }
    }
    bool isSimilar(const string& s1,const string& s2){
        int mismatches = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]) mismatches++;
        }
        return mismatches == 0 || mismatches == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        groupCount = n;
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    union1(i,j);
                }
            }
        }
        return groupCount;
    }
};