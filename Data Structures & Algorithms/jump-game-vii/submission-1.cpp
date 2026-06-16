class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    if (s[n - 1] != '0') return false;

    vector<bool> canReach(n, false);
    canReach[0] = true;
    int count = 0; // Tracks reachable '0's in the valid jump window

    for (int i = 1; i < n; i++) {
        // Maintain window: add index entering the range
        if (i >= minJump) count += canReach[i - minJump];
        // Maintain window: remove index leaving the range
        if (i > maxJump) count -= canReach[i - maxJump - 1];
        
        if (count > 0 && s[i] == '0') {
            canReach[i] = true;
        }
    }
    return canReach[n - 1];
}
};