class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp;
        for(string &word : wordList){
            mp.insert(word);
        }    
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string currWord = top.first;
            int currDist = top.second;

            if(currWord == endWord){
                return currDist;
            }
            
            for(int i=0;i<currWord.size();i++){
                // string currCharacter = CurrWord[i];
                for(int j=0;j<26;j++){
                    string CopyCurrWord = currWord;
                    CopyCurrWord[i] = 'a' + j;
                    if(mp.find(CopyCurrWord) != mp.end()){
                        q.push({CopyCurrWord,currDist+1});
                        mp.erase(CopyCurrWord);
                    } 
                }
            }
        }
        return 0;
    }
};