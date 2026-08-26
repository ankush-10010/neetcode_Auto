class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int> state;
        state["00000"] = -1;
        vector<int> vowel(5,0);
        int maxLen = -1e9;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a') vowel[0] ^= 1;
            else if(s[i] == 'e') vowel[1] ^= 1;
            else if(s[i] == 'i') vowel[2] ^= 1;
            else if(s[i] == 'o') vowel[3] ^= 1;
            else if(s[i] == 'u') vowel[4] ^= 1;

            string currState = "";
            for(int s : vowel){
                currState += to_string(s);
            }

            if(state.count(currState)){
                int currLen = i - state[currState];
                maxLen = max(maxLen,currLen);
            }else{
                state[currState] = i;
            }
        }

        return (maxLen == -1e9) ? 0 : maxLen;
    }
};


