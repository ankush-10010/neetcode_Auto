class Solution {
    vector<int> parent;
public:
    int findParent(int x){
        if(parent[x] == x) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void union1(int x,int y){
        int leaderX = findParent(x);
        int leaderY = findParent(y);

        if(leaderX != leaderY){
            if(leaderX < leaderY){
                parent[leaderY] = leaderX;
            }else{
                parent[leaderX] = leaderY;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }

        for(int i=0;i<s1.size();i++){
            int charA = s1[i] - 'a';
            int charB = s2[i] - 'a';

            union1(charA,charB);
        }

        string result = "";
        for(int i=0;i<baseStr.size();i++){
            int currCharacter = baseStr[i] - 'a';
            int index = findParent(currCharacter);
            result += (char)(index + 'a');
        }

        return result;
    }
};