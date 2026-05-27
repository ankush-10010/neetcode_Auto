class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "D"){
                int to_add = s.top()*2;
                s.push(to_add); 
            }else if(operations[i] == "+"){
                int prev1 = s.top();
                s.pop();
                int prev2 = s.top();
                s.pop();
                int to_add = prev1+prev2;
                s.push(prev2);
                s.push(prev1);
                s.push(to_add);
            }else if(operations[i] == "C"){
                s.pop();
            }else{
                s.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!s.empty()){
            result+=s.top();
            s.pop();
        }
        return result;
    }
};


// what is the significance of the 32bit integer information