class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
    void dfs(int index , string& s,vector<string>& current){
        // result.push_back(current);
        if(index == s.size()){
            result.push_back(current);
        }// should have checked if it was a palindrome
        for(int i=index;i<s.size();i++){
            // at each i we should be aware of where to make the cut
            // if we make a cut i , we also should also know where the last cut was made
            string newString = s.substr(index,i-index+1);
            if(isPalindrome(newString)){
                current.push_back(newString);
                dfs(i+1,s,current);
                current.pop_back();
                // dfs(i+1,s,current);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        dfs(0,s,current);
        return result;
    }
};
