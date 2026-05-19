class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;


        while(getline(ss,dir,'/')){
            if(dir == "" || dir == "."){
                continue;
            }else if(dir == ".."){
                if(!stack.empty()){
                    stack.pop_back();
                }
            }else{
                stack.push_back(dir);
            }
        }

        string result = "";
        for(const string& s : stack){
            result += "/" + s;
        }

        return result.empty() ? "/" : result;
    }
};