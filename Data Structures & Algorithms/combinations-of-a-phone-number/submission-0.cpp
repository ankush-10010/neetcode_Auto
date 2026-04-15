class Solution {
public:
    vector<string> output;

    string mapping[10] = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };

    void dfs(int index , string& digits,string& current){
        if(index == digits.size()){
            output.push_back(current);
            return;
        }

        int digit = digits[index] - '0';//this is already an integer
        for(char c : mapping[digit]){
            current.push_back(c);
            dfs(index+1,digits,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};  
        }
        
        string current = "";
        dfs(0,digits,current);

        return output;
    }
};
