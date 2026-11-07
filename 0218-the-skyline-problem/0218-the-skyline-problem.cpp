class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // first we will need to create the outlines
        // to bypass the deletion from a priority queue we use the 
        // lazy deletion method 
        auto cmp_b = [](const vector<int>& a,const vector<int>& b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            if((a[0] == b[0]) && (a[1] == b[1])){
                return a[2] < b[2];
            }
            return a[0] < b[0];
        };
        vector<pair<int,int>> coordinates;
        for(int i=0;i<buildings.size();i++){
            coordinates.push_back({buildings[i][0],i});
            coordinates.push_back({buildings[i][1],i});
        }
        sort(coordinates.begin(),coordinates.end());
        // sort(buildings.begin(),buildings.end(),cmp_b);
        int prevMaxHeight = 0;
        vector<vector<int>> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq; // height , right x
        int i=0;
        while(i<coordinates.size()){
            // int currentLeft = buildings[i][0];
            // int currentRight = buildings[i][1];
            int currentX = coordinates[i].first;
            while (i < coordinates.size() && coordinates[i].first == currentX){
                int currentIndex = coordinates[i].second;
                int currentHeight = buildings[currentIndex][2];
                if(currentX == buildings[currentIndex][0]){
                    pq.push({currentHeight,buildings[currentIndex][1]});
                }  
                i++; 
            }
            
            while(!pq.empty() && pq.top().second <= currentX){
                pq.pop();
            }
            int currentHeightPQ = 0;
            if(!pq.empty()){
                currentHeightPQ = pq.top().first;
            }
            if(prevMaxHeight != currentHeightPQ){
                vector<int> current(2);
                current[0] = currentX;
                current[1] = currentHeightPQ;
                prevMaxHeight = currentHeightPQ;
                result.push_back(current);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};