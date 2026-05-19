class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>> st;

        string curr_str = "";
        int curr_num = 0;

        for(char c: s){
            if(isdigit(c)){
                curr_num = curr_num*10 + (c-'0');
            }else if(c == '['){
                st.push({curr_str,curr_num});
                curr_str = "";
                curr_num = 0;
            }else if(c == ']'){
                auto prev_state = st.top();
                st.pop();

                string prev_str = prev_state.first;
                int prev_int = prev_state.second;

                string temp = "";
                for(int i=0;i<prev_int;i++){
                    temp += curr_str;    
                }

                curr_str = prev_str + temp;
            }else if (isalpha(c)) {
                // Just add letters to our current string
                curr_str += c;
            }
        }
        return curr_str;
    }
};