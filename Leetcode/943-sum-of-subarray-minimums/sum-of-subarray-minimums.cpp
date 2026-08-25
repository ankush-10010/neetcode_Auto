class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9+7;
        int n = arr.size();
        vector<int> leftBound(n, -1); 
        stack<int> st_left;

        for (int i = 0; i < n; i++) {
            while (!st_left.empty() && arr[st_left.top()] > arr[i]) {
                st_left.pop();
            }
            if (!st_left.empty()) {
                leftBound[i] = st_left.top();
            }
            st_left.push(i);
        }

        vector<int> rightBound(n,n);
        stack<int> st_right;

        for(int i=n-1;i>=0;i--){
            while(!st_right.empty() && arr[st_right.top()] >= arr[i]){
                st_right.pop();
            }
            if(!st_right.empty()){
                rightBound[i] = st_right.top();
            }
            st_right.push(i);
        }

        long long total = 0;
        for(int i=0;i<n;i++){
            long long left = (i-leftBound[i])%MOD;
            long long right = (rightBound[i]-i)%MOD;
            long long current = arr[i];
            total = (total + (left*right*current)%MOD)%MOD;
        }
        return total;
    }
};
