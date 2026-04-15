class Solution {
public:
    string expandFromCenter(string &s,int left,int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
           left--;
           right++; 
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        // make an dp array of s.size() size
        // meaning -> longest plaindrome till size n
        string ans = "";
        for(int i=0;i<s.size();i++){
            string p1 = expandFromCenter(s,i,i);
            string p2 = expandFromCenter(s,i,i+1);

            if(p1.size() > ans.size()){
                ans = p1;
            }
            if(p2.size() > ans.size()){
                ans = p2;
            }
        }
        return ans;
    }
};
