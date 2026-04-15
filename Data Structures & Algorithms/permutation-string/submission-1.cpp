class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int>s1_freq(26,0);
        vector<int>window_freq(26,0);
        for(int i=0;i<s1.size();i++){
            s1_freq[s1[i]-'a']++;
            window_freq[s2[i]-'a']++;
        }

        for(int i=0;i<=(s2.size()-s1.size());i++){
            if(s1_freq == window_freq){
                return true;
            }
            if(i+s1.size() < s2.size()){
                window_freq[s2[i] - 'a']--;
                window_freq[s2[i+s1.size()] - 'a']++;
            }
        }
        return false;
    }
};
