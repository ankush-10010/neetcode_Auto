class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string key(26,0);
            for(char c:s){
                key[c-'a']++;
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());
        for(auto& p: mp){
            result.push_back(move(p.second));
        }

        return result;
    }
};
