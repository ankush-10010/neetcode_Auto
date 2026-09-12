struct Interval {
    long long l, r, w;
    int id;
};

struct State {
    long long weight;
    int sz;
    array<int, 4> indices;

    bool operator<(const State& other) const {
        if (weight != other.weight) {
            return weight < other.weight;
        }
        
        for (int i = 0; i < min(sz, other.sz); ++i) {
            if (indices[i] != other.indices[i]) {
                return indices[i] > other.indices[i];
            }
        }
        return sz > other.sz;
    }
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> ivs(n);
        
        for (int i = 0; i < n; ++i) {
            ivs[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(ivs.begin(), ivs.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id;
        });
        
        vector<long long> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = ivs[i].l;
        }
        
        vector<vector<State>> dp(n + 1, vector<State>(5, {0, 0, {0, 0, 0, 0}}));
        
        for (int i = n - 1; i >= 0; --i) {
            int j = upper_bound(starts.begin(), starts.end(), ivs[i].r) - starts.begin();
            
            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i + 1][k];
                State take = dp[j][k - 1];
                take.weight += ivs[i].w;
                take.indices[take.sz] = ivs[i].id;
                take.sz++;

                int pos = take.sz - 1;
                while (pos > 0 && take.indices[pos - 1] > take.indices[pos]) {
                    swap(take.indices[pos - 1], take.indices[pos]);
                    pos--;
                }
                
                if (skip < take) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < dp[0][4].sz; ++i) {
            ans.push_back(dp[0][4].indices[i]);
        }
        return ans;
    }
};