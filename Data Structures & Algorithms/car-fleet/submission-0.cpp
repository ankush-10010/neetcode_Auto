class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<double> st;
        for(int i=cars.size()-1;i>=0;i--){
            double time = (double) (target - cars[i].first)/ cars[i].second;
            if(st.empty() || time>st.top()){
                st.push(time);
            }
        }
        int output = 0;
        while(!st.empty()){
            output++;
            st.pop();
        }
        return output;
    }
};
