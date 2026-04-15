class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char,int> charLastidx;
        for(int i=0;i<s.size();i++){
            char current = s[i];
            charLastidx[current] = i;
        }// this should update give the map of every characters last index
        
        int currend = 0; /*will be updated throughout the loop*/
        /* int lastidx --> character's last index , from map */
        int left = 0;
        for(int right=0;right<s.size();right++){
            char currentChar = s[right];
            currend = max(currend , charLastidx[currentChar]);
            int lastidx = charLastidx[currentChar];
            if(right == currend){
                // --> calculate the length of the substring here now
                int length = right - left + 1;
                result.push_back(length);
                left = right + 1;
            }
        }
        return result;
    }
};
