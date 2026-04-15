class Solution {
public:
    int HelperFunction(string s, int left, int right){
        int countInternal = 0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            countInternal++;
        }
        return countInternal;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            int count1 = HelperFunction(s,i,i);
            int count2 = HelperFunction(s,i,i+1);
            count += count1;
            count += count2;
        }
        return count;
    }
};
