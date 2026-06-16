class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> rad_q;
        queue<int> dir_q;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rad_q.push(i);
            } else {
                dir_q.push(i);
            }
        }

        while (!rad_q.empty() && !dir_q.empty()) {
            int r_idx = rad_q.front();
            int d_idx = dir_q.front();
            
            rad_q.pop();
            dir_q.pop();
            
            // The one with the smaller index goes first and eliminates the other
            if (r_idx < d_idx) {
                // Radiant wins this matchup, goes to the back of the line for next round
                rad_q.push(r_idx + n); 
            } else {
                // Dire wins this matchup, goes to the back of the line for next round
                dir_q.push(d_idx + n);
            }
        }
        
        // 3. The queue that isn't empty is the winner
        if (rad_q.empty()) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};