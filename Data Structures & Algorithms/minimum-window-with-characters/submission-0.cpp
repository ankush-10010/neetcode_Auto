class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char,int> string_freq;
        for(char c: t){
            string_freq[c]++;
        }
        /*now i have a sliding window map where i have 
        frequency of each element in the string t stored in this
        */
        /*
        one approach i have is to use two pointer left and right 
        and start populating the freq variable untill i 
        */
        unordered_map<char,int> window_freq;
        int left = 0;
        int minLength = INT_MAX;
        int unique_elements = string_freq.size();
        int have = 0;
        int startIdx = 0;
        for(int right = 0; right<s.size(); right++){
            window_freq[s[right]]++;
            if(string_freq.count(s[right]) && window_freq[s[right]] == string_freq[s[right]]){
                have++;
            }

            while(have == unique_elements){
                if((right - left + 1) < minLength){
                    minLength = right - left + 1;
                    startIdx = left;
                }
                char leftChar = s[left];
                if(string_freq.count(leftChar) && window_freq[leftChar] == string_freq[leftChar]){
                    have--;
                }
                window_freq[leftChar]--;
                left++;
            }
        }
        
        return (minLength == INT_MAX) ? "" : s.substr(startIdx,minLength);
    }
};
