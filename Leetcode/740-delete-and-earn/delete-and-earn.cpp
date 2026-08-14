class Solution {
public:
    int solve(int i,vector<int>& memo,unordered_map<int,int>& mp){
        if(i==0) return 0;
        if(i==1) return max(mp[1]*1,mp[0]*0);
        if(memo[i] != -1) return memo[i];
        int skip = solve(i-1,memo,mp);
        int take = mp[i]*i + solve(i-2,memo,mp);
        return memo[i] = max(skip,take);
    }
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> freq;
        int max_num = INT_MIN;
        for(int num : nums){
            freq[num]++;
            max_num = max(max_num,num);
        }
        
        vector<int> memo(max_num+1,-1);
        return solve(max_num,memo,freq);
    }
};