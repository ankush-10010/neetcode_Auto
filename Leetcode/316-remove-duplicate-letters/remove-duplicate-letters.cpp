class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<pair<char,int>> st;
        unordered_map<char,pair<int,vector<int>>> mp;
        unordered_map<char,bool> seen;
        for(int i=0;i<s.size();i++){
            char currChar = s[i];
            int currCount = 0;
            if(mp[currChar].first != 0){
                currCount = mp[currChar].first;
            }
            currCount++;
            mp[currChar].first = currCount;
            mp[currChar].second.push_back(i);
        }

        for(int i=s.size()-1;i>=0;i--){
            st.push({s[i],i});
        }
        string result = "";

        while(!st.empty()){
            auto top = st.top();
            char currChar = top.first;
            int currIndex = top.second;
            st.pop();
            mp[currChar].first--;
            if(seen[currChar]) continue;

            while(!result.empty() && currChar < result.back() && mp[result.back()].first>0){
                seen[result.back()] = false;
                result.pop_back();
            }
            result.push_back(currChar);
            seen[currChar] = true;
        }
        return result;
    }
};


// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         int n = s.size();
//         int last[26] = {0};
//         for (int i = 0; i < n; ++i) {
//             last[s[i] - 'a'] = i;
//         }
//         string ans;
//         int mask = 0;
//         for (int i = 0; i < n; ++i) {
//             char c = s[i];
//             if ((mask >> (c - 'a')) & 1) {
//                 continue;
//             }
//             while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
//                 mask ^= 1 << (ans.back() - 'a');
//                 ans.pop_back();
//             }
//             ans.push_back(c);
//             mask |= 1 << (c - 'a');
//         }
//         return ans;
//     }
// };