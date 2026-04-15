class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0){
            int last_digit = x%10;
            if(INT_MAX/10 < result){
                return 0;
            }
            if(INT_MIN/10 > result){
                return 0;
            }
            result = result*10 + last_digit;
            x = x/10;
        }
        // result = result*10 + x;
        return result;
    }
};
