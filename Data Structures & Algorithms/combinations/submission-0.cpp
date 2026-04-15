class Solution {
public:
    vector<vector<int>> result;
    void dfs(int index,vector<int>& current,vector<int>& numbers,int k){
        if(current.size() == k){
            result.push_back(current);
            return;
        }
        if(index == numbers.size()){
            return;
        }
        current.push_back(numbers[index]);
        dfs(index+1,current,numbers,k);
        current.pop_back();
        dfs(index+1,current,numbers,k);
    }
    vector<vector<int>> combine(int n, int k) {
        if(n==0){
            return {};
        }
        vector<int> current;
        vector<int> numbers;
        for(int i=1;i<n+1;i++){
            numbers.push_back(i);
        } 
        dfs(0,current,numbers,k);
        return result;
    }
};