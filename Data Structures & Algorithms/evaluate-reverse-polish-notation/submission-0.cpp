class Solution {
public:
    bool isOperator(string &s){
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int num;
        for(int i=0;i<tokens.size();i++){
            int num1 , num2;
            if(!isOperator(tokens[i])){
                stack.push(stoi(tokens[i]));
            }else{
                if(tokens[i]=="+"){
                    num2=stack.top();
                    stack.pop();
                    num1=stack.top();
                    stack.pop();
                    num=num1+num2;
                    stack.push(num);
                }
                if(tokens[i]=="-"){
                    num2=stack.top();
                    stack.pop();
                    num1=stack.top();
                    stack.pop();
                    num=num1-num2;
                    stack.push(num);
                }
                if(tokens[i]=="*"){
                    num2=stack.top();
                    stack.pop();
                    num1=stack.top();
                    stack.pop();
                    num=num1*num2;
                    stack.push(num);
                }
                if(tokens[i]=="/"){
                    num2=stack.top();
                    stack.pop();
                    num1=stack.top();
                    stack.pop();
                    num=num1/num2;
                    stack.push(num);
                }
            }
        }
        return stack.top();
    }
};
