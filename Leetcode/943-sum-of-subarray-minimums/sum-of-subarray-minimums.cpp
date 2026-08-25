class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;
        stack<int> st;
        long long totalCount = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){
                int mid = st.top();
                st.pop();

                int leftBound = st.empty() ? -1 : st.top();
                int rightBound = i;

                long long subArrays_sum = (1LL*(mid-leftBound)*(rightBound-mid)) % MOD;
                totalCount = (totalCount + (subArrays_sum * arr[mid]) % MOD) % MOD;
            }
            st.push(i);
        }

        return totalCount;
    }
};