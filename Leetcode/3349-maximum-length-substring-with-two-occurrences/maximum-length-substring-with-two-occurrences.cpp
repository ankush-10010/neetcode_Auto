class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_map<char,int> freq;
        for(int right =0;right<s.size();right++){
            char c = s[right];
            freq[c]++;
            while(freq[c] > 2 && left < right){
                char cc = s[left];
                freq[cc]--;
                left++;
            }

            maxLen =max(maxLen,right-left+1);
        }

        return maxLen;
    }
};