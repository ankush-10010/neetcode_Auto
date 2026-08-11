class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> count; // row , count
        for(int i=0;i<mat.size();i++){
            int c1 = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    c1++;
                }else{
                    break;
                }
            }
            count.push_back({c1,i});
        }
        for(auto c : count){
            cout << format("row-->{} and count-->{}",c.second,c.first)<<endl;
        }
        sort(count.begin(),count.end());
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(count[i].second);
        }

        return result;
    }
};