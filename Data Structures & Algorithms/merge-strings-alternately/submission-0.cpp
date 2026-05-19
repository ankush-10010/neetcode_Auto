class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int start1=0;
        int start2=0;
        string output = "";
        while(start1 < word1.size() && start2 < word2.size()){
            output += word1[start1];
            output += word2[start2];
            start1++;
            start2++;
        }
        if(start1 == word1.size()){
            for(int i=start2;i<word2.size();i++){
                output += word2[i];
            }
        }else if(start2 == word2.size()){
            for(int i=start1;i<word1.size();i++){
                output += word1[i];
            }
        }

        return output;
    }
};