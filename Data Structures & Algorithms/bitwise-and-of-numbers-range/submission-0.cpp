class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // take every single number in this range and perform bitwise AND
        int shifts = 0;
        while(left < right){
            left >>= 1;
            right >>= 1;
            shifts++;
        }

        return left << shifts;
    }
};