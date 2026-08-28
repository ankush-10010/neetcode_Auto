class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> orig_freq(26, 0);
        for(char c : s) {
            int char_index = c - 'a';
            orig_freq[char_index]++;
        }
        
        vector<int> half_freq(26, 0);
        char mid_char = 0;
        int odd_count = 0;

        for(int i = 0; i < 26; i++) {
            if(orig_freq[i] % 2 != 0) {
                odd_count++;
                mid_char = i + 'a';
            }
            half_freq[i] = orig_freq[i] / 2;
        }
        
        if(odd_count > 1) return "";
        int half_n = n / 2;
        
        bool can_form_exact = true;
        vector<int> exact_freq = half_freq;
        string exact_half = "";
        
        for(int i = 0; i < half_n; i++) {
            int char_idx = target[i] - 'a';
            if(exact_freq[char_idx] > 0) {
                exact_freq[char_idx]--;
                exact_half += target[i];
            } else {
                can_form_exact = false;
                break;
            }
        }
        
        if(can_form_exact) {
            string exact_pal = exact_half;
            if(n % 2 != 0) exact_pal += mid_char;
            
            string rev_half = exact_half;
            reverse(rev_half.begin(), rev_half.end());
            exact_pal += rev_half;
            
            if(exact_pal > target) {
                return exact_pal; 
            }
        }

        string result = "";
        bool found = false;
        
        for(int i = half_n - 1; i >= 0; i--) {
            vector<int> freq = half_freq;
            bool can_form_prefix = true;

            for(int j = 0; j < i; j++) {
                int char_idx = target[j] - 'a';
                if(freq[char_idx] > 0) {
                    freq[char_idx]--;
                } else {
                    can_form_prefix = false;
                    break;
                }
            }

            if(!can_form_prefix) continue;
            
            int target_char_idx = target[i] - 'a';
            for(int c = target_char_idx + 1; c < 26; c++) {
                if(freq[c] > 0) {
                    freq[c]--; 
                    
                    result = target.substr(0, i); 
                    result += (char)(c + 'a');

                    for(int k = 0; k < 26; k++) {
                        while(freq[k] > 0) { 
                            result += (char)(k + 'a');
                            freq[k]--;
                        }
                    }
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        if(result == "") return "";
        
        string final_pal = result;
        if(n % 2 != 0) final_pal += mid_char;

        reverse(final_pal.begin(), final_pal.end());
        result += final_pal;
        
        return result;
    }
};