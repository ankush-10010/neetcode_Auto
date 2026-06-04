class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> milestoneChanges(1001,0);
        for(const auto& trip:trips){
            int numPassengers = trip[0];
            int fromLocation = trip[1];
            int toLocation = trip[2];

            milestoneChanges[fromLocation] += numPassengers;
            milestoneChanges[toLocation] -= numPassengers;    
        }

        int currentPassengers = 0;
        for(int i=0;i<1000;i++){
            currentPassengers += milestoneChanges[i];

            if(currentPassengers > capacity){
                return false;
            }
        }
        return true;
    }
};