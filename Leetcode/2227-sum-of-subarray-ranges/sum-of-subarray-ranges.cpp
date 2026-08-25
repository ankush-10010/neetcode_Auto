class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minPrev(n,-1);
        vector<int> minNext(n,n);
        vector<int> maxPrev(n,-1);
        vector<int> maxNext(n,n);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                minPrev[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                minNext[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                maxPrev[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                maxNext[i] = st.top();
            }
            st.push(i);
        }

        long long total = 0;
        for(int i=0;i<n;i++){
            long long leftMinChoices = i - minPrev[i];
            long long rightMinChoices = minNext[i] - i;
            long long minSubarrays = rightMinChoices*leftMinChoices;

            long long leftMaxChoices = i - maxPrev[i];
            long long rightMaxChoices = maxNext[i] - i;
            long long maxSubarrays = rightMaxChoices*leftMaxChoices;

            total += (maxSubarrays * nums[i]) - (minSubarrays * nums[i]);
        }

        return total;
    }
};