class Solution {
public:
    int numTilings(int n) {
        long long MOD = 1e9 + 7;
        vector<long long> partial(n+1,0);
        vector<long long> full(n+1,0);
        full[0] = 1;
        full[1] = 1;
        partial[1] = 0;
        // full[2] = 2;
        for(int i=2;i<=n;i++){
            partial[i] = (full[i-2] + partial[i-1] % MOD); 
            full[i] = (full[i-1] + full[i-2] + 2*partial[i-1]) % MOD;
        }
        return full[n] % MOD;
    }
};