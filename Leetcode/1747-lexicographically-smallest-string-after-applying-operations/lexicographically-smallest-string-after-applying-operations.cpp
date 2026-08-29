class Solution {
public:
    void dfs(string &s,int a,int b,string& minString,unordered_set<string>& visited){
        if(visited.find(s) != visited.end()) return;
        visited.insert(s);
        string o1 = s;
        string o2 = s;
        minString = min({minString,o1,o2});
        operation1(o1,a);
        operation2(o2,b);
        dfs(o1,a,b,minString,visited);
        dfs(o2,a,b,minString,visited);
    }
    void operation1(string &s,int a){
        for(int i=0;i<s.size();i++){
            if(i%2 != 0){
                int currNumber = s[i] - '0';
                int newNumber = (currNumber + a)%10;
                // string newChar = to_string(newNumber);
                char newChar = newNumber + '0';
                s[i] = newChar;
            }    
        }
    }
    void operation2(string &s,int b){
        int n = s.size();
        string temp = s;
        for(int i=0;i<s.size();i++){
            int newIndex = (i+b)%n;
            temp[newIndex] = s[i];
        }
        for(int i=0;i<s.size();i++){
            s[i] = temp[i];
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        string minString = s;
        unordered_set<string> visited;
        // visited.insert(s);
        dfs(s,a,b,minString,visited);
        return minString;
    }
};