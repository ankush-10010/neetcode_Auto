class Solution {
public:
    string digitSum(string s, int k) {
        int count = 0;
        while(s.size() > k){
            count++;
            string newString = "";
            for(int i=0;i<s.size();i+=k){
                int currentSum = 0;
                for(int j = i; j < i + k && j < s.size(); j++){
                    currentSum += s[j] - '0';
                }
                newString += to_string(currentSum);
            }
            s = newString;
            // cout << format("count --> {}",count) << endl;
            // cout << "size --> " << s.size() << endl;
        }

        return s;
    }
};