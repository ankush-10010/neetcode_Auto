class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int m = 0;
        int total = 0;
        for(int weight : weights){
            m = max(m,weight);
            total += weight;
        }
        // the answer will always be >= m for sure
        // the answer will always be <= total
        // now m and total works and lower and upper bounds 

        while(m < total){
            int mid = m + (total - m)/2;
            int daysNeeded = 1;
            int currentLoad = 0;

            for(int i=0;i<weights.size();i++){
                if(currentLoad + weights[i] > mid){
                    daysNeeded++;
                    currentLoad = weights[i];
                }else{
                    currentLoad += weights[i];
                }
            }

            if(daysNeeded > days){
                m = mid + 1;
            }else{
                total = mid;
            }
        }
        return m;   
        
    }
};