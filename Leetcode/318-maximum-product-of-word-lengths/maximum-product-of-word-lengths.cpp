class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> lengths(n,0);
        vector<int> masks(n,0);
        for(int i=0;i<words.size();i++){
            lengths[i] = words[i].size();
        }
        for(int i=0;i<n;i++){
            int mask = 0;
            for(char c : words[i]){
                int shift = c-'a';
                mask |= (1<<shift);
            }
            masks[i] = mask;

        }   

        int maxP = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((masks[i]&masks[j]) == 0){
                    int products = lengths[i]*lengths[j];
                    maxP = max(maxP,products);
                }
            }
        }
        return maxP;
    }
};