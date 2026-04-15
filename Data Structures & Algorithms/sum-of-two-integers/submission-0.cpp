class Solution {    
public:
    int getSum(int a, int b) {
        //have to implement a full adder basically
        // a and b can be of any bits so we will have to be considerate about the Cin part of
        // full adder too
        while(b != 0){
            int carry = (a&b) << 1;
            a = a^b;
            b = carry;
        }
        return a;
    }
};
