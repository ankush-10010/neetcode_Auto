class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        int m = num1.length();
        int n = num2.length();

        vector<int> result(m+n,0);

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum =  mul + result[i+j+1];
                result[i+j+1] = sum%10;
                result[i+j] += sum/10;
            }
        }

        string finalString = "";
        for(int digit : result){
            if(!(finalString.empty() && digit == 0)){
                finalString += to_string(digit);
            }
        }

        return finalString;
    }
};
