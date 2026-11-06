class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<int,int> freq_s1;
        for(int i=0;i<s1.size();i++){
            int currChar = s1[i] - 'a';
            freq_s1[currChar]++;
        }

        int left = 0;
        int right = 0;
        unordered_map<int,int> freq_s2;
        while(right < s2.size()){
            int currChar = s2[right] - 'a';
            freq_s2[currChar]++;
            //when to shrink , increase left
            while(freq_s2[currChar] > freq_s1[currChar] && left <= right){
                int leftCurrChar = s2[left] - 'a';
                freq_s2[leftCurrChar]--;

                if(freq_s2[leftCurrChar] == 0){
                    freq_s2.erase(leftCurrChar);
                }
                left++;
            }

            bool matched = true;
            for(auto& a: freq_s2){
                // cout << a.first << "\t" << a.second << endl;
                if(freq_s1[a.first] != a.second){
                    matched = false;
                }
            }
            cout << matched << endl;
            if(matched && freq_s2.size() == freq_s1.size()) return true;
            // otherwise expand , increase right
            right++;
        }

        return false;
    }
};
