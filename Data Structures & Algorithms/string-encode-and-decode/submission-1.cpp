#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s:strs){
            int length = s.size();
            encoded += to_string(length) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i < s.length()){
            int j = i;
            
            while(s[j] != '#'){
                j++;
            }

            // int length = stoi(s[j-1]);
            int length = stoi(s.substr(i,j-i));
            // int length = stoi(s.substr(i, j - i));
            string str = s.substr(j+1,length);
            result.push_back(str);

            i = j+ 1 + length;
        }
        return result;
    }
};
