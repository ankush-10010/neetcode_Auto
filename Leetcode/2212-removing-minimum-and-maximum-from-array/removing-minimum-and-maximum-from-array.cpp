class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        if(nums.size() == 2) return 2;
        pair<int,int> minN  = {-1,INT_MAX};
        pair<int,int> maxN = {-1,INT_MIN};

        for(int i =0;i<nums.size();i++){
            int currNumber = nums[i];
            if(currNumber >= maxN.second){
                maxN = {i,currNumber};
            }
            if(currNumber <= minN.second){
                minN = {i,currNumber};
            }
        }

        int indexMin = minN.first;
        int indexMax = maxN.first;

        int left = min(indexMin,indexMax);
        int right = max(indexMin,indexMax);
        // take all from left 
        int deletions1 = right + 1;
        // take all from right
        int deletions2 = nums.size() - left;
        // take from left to right
        int deletions3 = (left + 1) + (nums.size() - right);

        return min({deletions1,deletions2,deletions3});
    }
};