class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto& t: tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto& [src,dest] : adj){
            sort(dest.begin(),dest.end());
        }
        vector<string> route;
        route.push_back("JFK");
        backtrack("JFK",tickets.size(),adj,route);
        return route;
    }
private:
    bool backtrack(string current,int tickets_left,unordered_map<string,vector<string>>& adj,vector<string>& route){
        if(tickets_left == 0) return true;
        for(int i=0;i<adj[current].size();i++){
            string next_airport = adj[current][i];
            if(next_airport != ""){
                adj[current][i] = "";
                route.push_back(next_airport);

                if(backtrack(next_airport,tickets_left - 1,adj,route)) return true;
                route.pop_back();
                adj[current][i] = next_airport;
            }
        }
        return false;
    }
};
