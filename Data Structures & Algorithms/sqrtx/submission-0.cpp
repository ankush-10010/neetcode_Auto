class Solution {
public:
    int mySqrt(int num) {
        long long start = 0;
        long long end = num;
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end- start)/2;
            long long square = mid * mid ;
            
            if(square == num){
                return mid;
            }
            if(square < num){
                start = mid + 1;
                ans = mid;
            }
            if(square > num){
                end = mid - 1;
            }
        }
        return ans;
    }
};
