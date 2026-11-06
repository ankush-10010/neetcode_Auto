class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq_s1(26, 0);
        vector<int> freq_s2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            freq_s1[s1[i] - 'a']++;
        }
        
        int left = 0;
        int right = 0;
        
        while (right < s2.size()) {
            int currChar = s2[right] - 'a';
            freq_s2[currChar]++;

            if (right - left + 1 > s1.size()) {
                int leftCurrChar = s2[left] - 'a';
                freq_s2[leftCurrChar]--;
                left++;
            }
            
            if (right - left + 1 == s1.size()) {
                if (freq_s1 == freq_s2) {
                    return true;
                }
            }
            
            right++;
        }
        
        return false;
    }
};