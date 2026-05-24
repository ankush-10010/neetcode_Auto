class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alienMap[26];
        for(int i=0;i<order.length();i++){
            alienMap[order[i] - 'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.length(),w2.length());
            bool foundDifference = false;

            for(int j=0;j<len;j++){
                if(w1[j] != w2[j]){
                    if(alienMap[w1[j] - 'a'] > alienMap[w2[j] - 'a']){
                        return false;
                    }
                    foundDifference = true;
                    break;
                }
            }

            if(!foundDifference && w1.length() > w2.length()){
                return false;
            }
        }
        return true;    
    }
};