class Solution {
    string dp_table[60][40];
    bool visited_table[60][40];

    // DP to find the shortest & lexicographically smallest string of digits {2,3,4,6,8,9}
    string getOptimal23(int r2, int r3) {
        r2 = max(0, r2);
        r3 = max(0, r3);
        if (r2 == 0 && r3 == 0) return "";
        if (visited_table[r2][r3]) return dp_table[r2][r3];

        string best = "";
        bool first = true;
        
        int cand[6] = {2, 3, 4, 6, 8, 9};
        int c2_arr[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int c3_arr[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};

        for (int d : cand) {
            int nr2 = max(0, r2 - c2_arr[d]);
            int nr3 = max(0, r3 - c3_arr[d]);
            
            if (nr2 == r2 && nr3 == r3) continue; // Skip if digit makes no progress

            string res = to_string(d) + getOptimal23(nr2, nr3);
            sort(res.begin(), res.end()); // Keep digits sorted for smallest lexicographical value
            
            if (first) {
                best = res;
                first = false;
            } else {
                if (res.length() < best.length()) {
                    best = res;
                } else if (res.length() == best.length() && res < best) {
                    best = res;
                }
            }
        }
        
        visited_table[r2][r3] = true;
        return dp_table[r2][r3] = best;
    }

    string getMinSuffix(int r2, int r3, int r5, int r7) {
        string suf = getOptimal23(r2, r3);
        if (r5 > 0) suf.append(r5, '5');
        if (r7 > 0) suf.append(r7, '7');
        sort(suf.begin(), suf.end());
        return suf;
    }

    void divideDigit(int d, int& r2, int& r3, int& r5, int& r7) {
        while (d % 2 == 0 && d > 0) { r2 = max(0, r2 - 1); d /= 2; }
        while (d % 3 == 0 && d > 0) { r3 = max(0, r3 - 1); d /= 3; }
        while (d % 5 == 0 && d > 0) { r5 = max(0, r5 - 1); d /= 5; }
        while (d % 7 == 0 && d > 0) { r7 = max(0, r7 - 1); d /= 7; }
    }

public:
    string smallestNumber(string num, long long t) {
        // Clear DP Table for each test case cleanly
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                visited_table[i][j] = false;
            }
        }

        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        // Step 1: Prime factorization of t
        while (t % 2 == 0) { c2++; t /= 2; }
        while (t % 3 == 0) { c3++; t /= 3; }
        while (t % 5 == 0) { c5++; t /= 5; }
        while (t % 7 == 0) { c7++; t /= 7; }
        
        if (t > 1) return "-1"; 

        int n = num.length();
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Store prefix factor states. Using array<int, 4> avoids memory overheads of vectors
        vector<array<int, 4>> prefix_factors(n + 1);
        int cur2 = c2, cur3 = c3, cur5 = c5, cur7 = c7;
        
        for (int i = 0; i < first_zero; ++i) {
            divideDigit(num[i] - '0', cur2, cur3, cur5, cur7);
            prefix_factors[i + 1] = {cur2, cur3, cur5, cur7};
        }

        // Check exact match (if entirely zero-free and fits requirement)
        if (first_zero == n && cur2 == 0 && cur3 == 0 && cur5 == 0 && cur7 == 0) {
            return num;
        }

        // Step 2: Test keeping prefixes ending directly prior to a replacement digit
        for (int i = min(n - 1, first_zero); i >= 0; --i) {
            int rem_len = n - 1 - i;
            int req2 = (i == 0) ? c2 : prefix_factors[i][0];
            int req3 = (i == 0) ? c3 : prefix_factors[i][1];
            int req5 = (i == 0) ? c5 : prefix_factors[i][2];
            int req7 = (i == 0) ? c7 : prefix_factors[i][3];

            int start_digit = (num[i] - '0') + 1;
            for (int d = start_digit; d <= 9; ++d) {
                int r2 = req2, r3 = req3, r5 = req5, r7 = req7;
                divideDigit(d, r2, r3, r5, r7);

                string suffix = getMinSuffix(r2, r3, r5, r7);
                if (suffix.length() <= rem_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    
                    // Pad with '1's right before the final suffix items to keep it as small as possible
                    ans.append(rem_len - suffix.length(), '1');
                    ans += suffix;
                    return ans;
                }
            }
        }

        // Step 3: Impossible within same length bounds, step up 1 digit length (pad early with 1s)
        string suffix = getMinSuffix(c2, c3, c5, c7);
        int target_len = max(n + 1, (int)suffix.length());
        string ans = "";
        ans.append(target_len - suffix.length(), '1');
        ans += suffix;
        return ans;
    }
};