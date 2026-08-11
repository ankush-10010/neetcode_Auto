class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x; 
        }
        parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unionGroups(int x, int y) {
        int leaderX = find(x);
        int leaderY = find(y);
    
        if (leaderX != leaderY) {
            parent[leaderX] = leaderY; 
        }
    }

public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                int var1 = eq[0] - 'a'; 
                int var2 = eq[3] - 'a';
                unionGroups(var1, var2);
            }
        }
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                int var1 = eq[0] - 'a';
                int var2 = eq[3] - 'a';
                if (find(var1) == find(var2)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};