class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq_front;
        priority_queue<int, vector<int>, greater<int>> pq_back;
        
        int n = costs.size();
        int i = 0;
        int j = n - 1;      
        
        while (i < candidates && i <= j) {
            pq_front.push(costs[i]);
            i++;
        }
        
        while (n - 1 - j < candidates && i <= j) {
            pq_back.push(costs[j]);
            j--;
        }
        
        long long total_cost = 0;
        
        for (int step = 0; step < k; step++) {
            int val1 = pq_front.empty() ? INT_MAX : pq_front.top();
            int val2 = pq_back.empty() ? INT_MAX : pq_back.top();
            
            if (val1 <= val2) {
                total_cost += val1;
                pq_front.pop();
                
                if (i <= j) {
                    pq_front.push(costs[i]);
                    i++;
                }
            } else {
                total_cost += val2;
                pq_back.pop();
                
                if (i <= j) {
                    pq_back.push(costs[j]);
                    j--;
                }
            }
        }
        
        return total_cost;
    }
};