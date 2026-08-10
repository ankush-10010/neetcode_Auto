class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        long long current_sum = 0;
        long long max_score = 0;
        
        for (int i = 0; i < n; ++i) {
            int current_nums2 = pairs[i].first;
            int current_nums1 = pairs[i].second;
            minHeap.push(current_nums1);
            current_sum += current_nums1;
            
            if (minHeap.size() > k) {
                current_sum -= minHeap.top();
                minHeap.pop();
            }
            
            if (minHeap.size() == k) {
                long long current_score = current_sum * current_nums2;
                max_score = max(max_score, current_score);
            }
        }
        
        return max_score;
    }
};