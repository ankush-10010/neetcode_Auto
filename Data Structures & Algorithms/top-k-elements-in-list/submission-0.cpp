#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequencies
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        // 2. Use a Priority Queue (Max Heap) to store pairs: {frequency, number}
        priority_queue<pair<int, int>> pq;
        for (auto it : countMap) {
            pq.push({it.second, it.first}); // Push {count, number}
        }
        
        // 3. Extract the top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second); // Get the number
            pq.pop(); // Remove it from heap
        }
        
        return result;
    }
};