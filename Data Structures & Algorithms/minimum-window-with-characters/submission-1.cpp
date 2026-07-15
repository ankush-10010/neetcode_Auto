#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Arrays to act as fast frequency maps for ASCII characters
        vector<int> dict_t(128, 0);
        vector<int> window(128, 0);
        
        int need = 0; // Number of unique characters we need
        for (char c : t) {
            if (dict_t[c] == 0) {
                need++;
            }
            dict_t[c]++;
        }
        
        int have = 0; // Number of unique characters we currently have enough of
        int left = 0;
        int right = 0;
        
        // Track the minimum window [length, start_index]
        int min_len = INT_MAX;
        int min_start = 0;
        
        while (right < s.length()) {
            // 1. Add the right character to the window
            char c = s[right];
            window[c]++;
            
            // If this character is part of t and we hit the exact frequency required
            if (dict_t[c] > 0 && window[c] == dict_t[c]) {
                have++;
            }
            
            // 2. Shrink the window from the left as long as it remains valid
            while (left <= right && have == need) {
                // Update our minimum window tracker
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                
                // Remove the left character from the window
                char left_char = s[left];
                window[left_char]--;
                
                // If removing this character breaks our valid window status
                if (dict_t[left_char] > 0 && window[left_char] < dict_t[left_char]) {
                    have--;
                }
                
                left++; // Shrink
            }
            
            right++; // Expand
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};