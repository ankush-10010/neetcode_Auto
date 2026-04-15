class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        int n = strs.size();

        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            vector<string> group;
            group.push_back(strs[i]);
            visited[i]=true;

            string s1=strs[i];
            sort(s1.begin(),s1.end());

            for(int j=i+1;j<n;j++){
                if(visited[j]==true){
                    continue;
                }

                string s2=strs[j];
                sort(s2.begin(),s2.end());
                if(s1==s2){
                    group.push_back(strs[j]);
                    visited[j]=true;
                }
            }
            output.push_back(group);
        }
        return output;
    }
};
