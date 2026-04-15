class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxPile=max(maxPile,piles[i]);
        }
        int k_max=maxPile;
        int ans=maxPile;
        int k_start=1;
        int k_end=k_max;
        while(k_start<=k_end){
            int k_mid=k_start +(k_end-k_start)/2;
            long long countHours=0;

            for(int i=0;i<piles.size();i++){
                countHours+=(piles[i]+k_mid-1)/k_mid;
            }
            if(countHours<=h){
                ans=k_mid;
                k_end=k_mid-1;
            }else{
                k_start=k_mid+1;
            }
        }
        return ans;
    }
};
