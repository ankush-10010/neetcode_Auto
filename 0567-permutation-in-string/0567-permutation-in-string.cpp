class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<int,int> freq_s1;
        for(int i=0;i<s1.size();i++){
            int current_char = s1[i] - 'a';
            freq_s1[current_char]++;
        }

        int left = 0;
        int right = 0;
        unordered_map<int,int> freq_s2;
        while(right < s2.size()){
            int currentChar = s2[right] - 'a';
            freq_s2[currentChar]++;

            while(freq_s2[currentChar] > freq_s1[currentChar] && left <= right){
                int leftCurrentChar = s2[left] - 'a';
                freq_s2[leftCurrentChar]--;
                
                if(freq_s2[leftCurrentChar] == 0){
                    freq_s2.erase(leftCurrentChar);
                }
                left++;
            }

            bool matched = true;
            for(auto& a : freq_s2){
                if(freq_s1[a.first] != a.second){
                    matched = false;
                    break;
                }
            }

            if(matched && freq_s2.size() == freq_s1.size()){
                return true;
            }

            right++;
        }
        return false;
    }
};