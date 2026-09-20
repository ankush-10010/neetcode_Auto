class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i=0;i<s.size();i++){
            int index = i+1;
            int number = 'z' - s[i] + 1;
            total += index*number;
        }

        cout << 'z' - 'b' + 1;
        return total;
    }
};