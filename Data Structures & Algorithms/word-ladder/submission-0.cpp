class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());

        if(!wordset.count(endWord)){
            return 0;
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto top = q.front();
            string word = top.first;
            int steps = top.second;
            q.pop();
            if(word == endWord){
                return steps;
            }
            // change one of the letters of qword 
            for(int j=0;j<word.size();j++){
                char original = word[j];
                for(char i = 'a' ; i<='z' ; i++){
                    if(i == original){
                        continue;
                    }
                    word[j] = i;
                    if(wordset.count(word)){
                        q.push({word,steps+1});
                        wordset.erase(word);
                    }
                }
                word[j] = original;
            }   
        }
        return 0;
    }
};
