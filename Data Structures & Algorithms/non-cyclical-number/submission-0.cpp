class Solution {
private:
    int getNext(int n) {
        int sum = 0;
        while(n != 0){
            int individual = n % 10;
            sum += individual * individual;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // Fast pointer moves twice as fast as the slow pointer.
        // If there's a cycle, they will eventually meet.
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};