class Solution {
    int findInsertionIndex(const vector<int>& sub, int target) {
        int left = 0;
        int right = sub.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (sub[mid] == target) {
                return mid;
            } else if (sub[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1; 
            }
        }
        return left; 
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> sub;

        for (int i = 0; i < envelopes.size(); i++) {
            int currentHeight = envelopes[i][1];
            
            if (sub.empty() || sub.back() < currentHeight) {
                sub.push_back(currentHeight);
            } 
            else {
                int indexToReplace = findInsertionIndex(sub, currentHeight);
                
                sub[indexToReplace] = currentHeight;
            }
        }

        return sub.size();
    }
};