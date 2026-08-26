class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> state_sum(n+1,0);
        state_sum[0] = 0;
        int running_sum = 0;
        for(int i=0;i<n;i++){
            running_sum += nums[i];
            int currentModulo = ((running_sum % k) + k)%k;
            state_sum[i+1] = currentModulo;
        }

        unordered_map<int,int> mp;
        for(int state: state_sum){
            mp[state]++;
        }
        int total = 0;
        for(auto &[state,count] : mp){
            cout << format("state-->{}  count-->{}",state,count)<<"\t";
            total += (count*(count-1)/2);
        }
        cout << endl;

        return total;
    }
};