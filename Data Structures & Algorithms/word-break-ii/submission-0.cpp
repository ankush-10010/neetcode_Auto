class Solution {
public:
    void solve(int i,const string& s,const unordered_set<string>& dict,string current_sentence,vector<string>& output){
        if(i == s.size()){
            current_sentence.pop_back();
            output.push_back(current_sentence);
            return;
        }
        string current_word = "";
        for(int j=i;j<s.size();j++){
            current_word+=s[j];

            if(dict.find(current_word) != dict.end()){
                string temp = current_sentence;
                current_sentence += current_word;
                // cout<<"current_sent  "<< current_sentence<<endl;
                solve(j+1,s,dict,current_sentence+" ",output);
                current_sentence = temp;
            }
        }
           
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> output;

        solve(0,s,dict,"",output);
        return output;
    }
};

