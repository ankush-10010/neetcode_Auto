class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prev_day = st.top();
                result[prev_day] = i-prev_day;
                st.pop();
            }

            st.push(i);
        }
        return result;
    }
};
// the golden rule of the monotonic stack is we never look forward 
// we dont need to search the future because the for loop is bringing the future to us one day at a time 
