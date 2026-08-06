class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            mp[curr]++;
        }
        int count = 0;
        for(int num : nums){
            int complement = k - num;
            if(complement == num && mp[complement] >=2){
                mp[num]-=2;
                count++;
            }
            else if(complement != num && mp[complement] > 0 && mp[num]>0){
                mp[complement]--;
                count++;
                mp[num]--;
            }
        }

        for(const auto [key,value] : mp){
            cout << format("mp[{}] --> {}",key,value) << "\t";
        }
        cout << endl;
        return count;
    }
};