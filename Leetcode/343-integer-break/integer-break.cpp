class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;

        int q = n/3;
        int rem = n%3;

        if(rem == 0){
            return pow(3,q);
        }
        if(rem == 1) return pow(3,q-1)*4;
        if(rem == 2) return pow(3,q)*2;

        return 0;
    }
};