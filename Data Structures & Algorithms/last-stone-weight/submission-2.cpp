class Solution {
public:
    // priority_queue<int,vector<int>,greater<>>
    int lastStoneWeight(vector<int>& stones) {
        
        sort(stones.begin(),stones.end());
        while(stones.size() > 1){
            int n = stones.size();
            if((stones[n-1] - stones[n-2])==0){
                stones.pop_back();
                stones.pop_back();
            }else if((stones[n-1] - stones[n-2])!=0){
                int temp = stones[n-1] - stones[n-2];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(temp);
            }
            sort(stones.begin(),stones.end());
        }
        if(stones.size()==0){
            return 0;
        }else{
            return stones[0];
        }
    }
};
