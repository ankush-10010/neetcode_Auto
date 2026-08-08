class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // right_match[i] stores how many characters from the END of word2
        // can be perfectly matched using the suffix of word1 starting from index i.
        vector<int> right_match(n + 1, 0);
        
        // Step 1: Right-to-Left Precomputation
        int j = m - 1; // Start at the end of word2
        for (int i = n - 1; i >= 0; --i) {
            // If there's a match, we increase our matched count
            if (j >= 0 && word1[i] == word2[j]) {
                right_match[i] = right_match[i + 1] + 1;
                j--;
            } else {
                // Otherwise, it carries over the count from the right
                right_match[i] = right_match[i + 1];
            }
        }
        
        vector<int> ans;
        bool mistake_used = false;
        j = 0; // Reset j to start from the beginning of word2
        
        // Step 2: Left-to-Right Greedy Sweep
        for (int i = 0; i < n; ++i) {
            if (j == m) break; // We found the whole sequence, stop searching
            
            // Case 1: Exact Match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } 
            // Case 2: Mismatch, check if we can safely use our 1 mistake here
            else if (!mistake_used) {
                int chars_remaining = m - 1 - j;
                
                // Does the rest of word1 have enough perfect matches for the rest of word2?
                if (right_match[i + 1] >= chars_remaining) {
                    ans.push_back(i);
                    j++;
                    mistake_used = true; // Our one cheat code is spent!
                }
            }
        }
        
        // If we successfully found all 'm' characters, return the indices
        if (ans.size() == m) {
            return ans;
        }
        
        // Otherwise, no valid sequence was found
        return {};
    }
};