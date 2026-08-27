class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> original_freq(26, 0);
        for (char c : s) {
            original_freq[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {
            vector<int> freq = original_freq;
            bool can_form_prefix = true;

            for (int j = 0; j < i; j++) {
                int char_idx = target[j] - 'a';
                if (freq[char_idx] > 0) {
                    freq[char_idx]--;
                } else {
                    can_form_prefix = false;
                    break; 
                }
            }

            if (!can_form_prefix) continue;
            int target_char_idx = target[i] - 'a';
            for (int c = target_char_idx + 1; c < 26; c++) {
                if (freq[c] > 0) {

                    string result = target.substr(0, i); 
                    result += (char)(c + 'a');
                    freq[c]--;                        

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            result += (char)(k + 'a');
                            freq[k]--;
                        }
                    }
                    
                    return result;
                }
            }
        }
        
        return ""; 
    }
};