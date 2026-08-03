#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> mp;
    vector<string> route;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Build the adjacency list
        for (auto& ticket : tickets) {
            mp[ticket[0]].push_back(ticket[1]);
        }
        
        // Step 2: Sort destinations in descending order so we can use pop_back()
        for (auto& [airport, destinations] : mp) {
            sort(destinations.begin(), destinations.end(), greater<string>());
        }
        
        // Step 3: Start DFS from JFK
        dfs("JFK");
        
        // Step 4: Reverse the route since we added the dead-ends first
        reverse(route.begin(), route.end());
        
        return route;
    }
    
private:
    void dfs(string airport) {
        // While there are still outgoing flights from this airport
        while (!mp[airport].empty()) {
            // Get the lexicographically smallest destination
            string next_airport = mp[airport].back();
            // Remove the ticket so we don't use it again
            mp[airport].pop_back();
            // Travel to the next airport
            dfs(next_airport);
        }
        // No more outgoing flights? This airport is a dead end. 
        // Add it to the route.
        route.push_back(airport);
    }
};