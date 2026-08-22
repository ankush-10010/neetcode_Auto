class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        int new_n = n;
        while(n != 0){
            int UD = n%10;
            n=n/10;
            digitSum += UD;
            digitProduct *= UD;
        }

        cout << format("digitSum-->{}",digitSum) << endl;
        cout << format("digitProduct-->{}",digitProduct) << endl;
        int sum = digitSum + digitProduct;
        int ans = (new_n)%sum;
        cout << format("sum-->{} ans-->{}",sum,ans) << endl;
        return ans == 0;
    }
};