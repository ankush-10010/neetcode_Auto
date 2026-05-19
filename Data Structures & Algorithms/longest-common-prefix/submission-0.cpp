class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        sort(strs.begin(),strs.end());

        string first = strs.front();
        string last = strs.back();

        string result = "";

        for(int i=0;i<first.size();i++){
            if(first[i] == last[i]){
                result += first[i];
            }else{
                break;
            }
        }
        return result;
    }
};