class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a:arr){
            mp[a]++;
        }

        bool a = true;
        vector<int> result;
        for(const auto [a,count]: mp){
            result.push_back(count);
        }
        sort(result.begin(),result.end());
        for(int i=1;i<result.size();i++){
            if(result[i-1] == result[i]){
                a = false;
            }
        }
        
        for(int r : result){
            cout << r << "\t";
        }
        cout << endl;
        return a;
    }
};