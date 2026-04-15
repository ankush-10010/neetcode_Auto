class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charfreq(26,0);
        int left = 0;
        int maxfreq = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size() ; right++){
            charfreq[s[right]-'A']++;
            maxfreq = max(maxfreq,charfreq[s[right] - 'A']);

            while((right - left + 1) - maxfreq > k){
                charfreq[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength , right-left+1);
        }
        return maxLength;
    }
};
