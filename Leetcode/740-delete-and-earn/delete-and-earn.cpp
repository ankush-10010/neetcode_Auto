class Solution {
public:
    int sovle(unordered_map<int,int>& mp,int num,int &maxPoint,int &currPoint){
        mp[num]--;
        int c_n1 = mp[num-1];
        int c_n2 = mp[num+1];
        mp[num-1] = 0;
        mp[num+1] = 0;
        currPoint += num;
        maxPoint = max(maxPoint,currPoint);
        return 0;
    }
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> freq;
        int max_num = INT_MIN;
        for(int num : nums){
            freq[num]++;
            max_num = max(max_num,num);
        }
        // for(auto& [num,freq] : mp){
        //     solve(mp,num);
        // }
        vector<int> dp(max_num+1,0);
        dp[0] = (freq[0] > 0) ? 0*freq[0] : 0;
        dp[1] = 1*freq[1];

        for(int i=2;i<max_num+1;i++){
            dp[i] = max(dp[i-1],dp[i-2] + freq[i]*i);
        }

        return dp[max_num];
    }
};