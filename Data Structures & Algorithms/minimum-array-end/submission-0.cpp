class Solution {
public:
    long long minEnd(int n, int x) {
        // construct a strictly increasing arr of size n 
        // bitwise AND of all element equals x
        // smallest value for arr[n-1]
        long long result = x;
        long long v = n-1;
        long long bit_position = 1;
        while(v > 0){
            if((x & bit_position) == 0){
                long long v_bit = (v&1);

                if(v_bit){
                    result |= bit_position;
                }

                v>>=1;
            }
            bit_position <<=1;
        }
        return result;
    }
};