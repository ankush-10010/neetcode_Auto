class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;

        unordered_map<int,int> mp;
        // priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        int ans = 0;
        while(right < s.size()){
            int currentChar = s[right] - 'A';
            mp[currentChar]++;

            // most freq char from left to right sliding window ?
            int mostFreq;
            int currentMaxFreq = 0;
            for(auto& a: mp){
                int currentChar = a.first;
                int currentFreq = a.second;
                if(a.second > currentMaxFreq){
                    currentMaxFreq = a.second;
                    mostFreq = currentChar;
                }
            }

            int replacements_needed = (right - left + 1) - (currentMaxFreq);
            if(replacements_needed <= k){
                ans = max(ans , right - left + 1);
            }
            
            while(left < s.size() && (right - left + 1 - currentMaxFreq)> k){
                int currentLeftChar = s[left] - 'A';
                mp[currentLeftChar]--;  
                left++;
            }

            right++;

        }

        return ans;
    }
};
