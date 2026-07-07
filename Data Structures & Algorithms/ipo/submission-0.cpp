class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       auto cmp = [](const pair<int,long long>& a, const pair<int,long long>& b){
            return a.first < b.first;
       };
       priority_queue<pair<int,long long>,vector<pair<int,long long>>,decltype(cmp)> pq(cmp);
       /// {profit , captial}
       vector<pair<int,long long>> capitals(profits.size(),{0,0});
       for(int i=0;i<profits.size();i++){
            capitals[i] = {profits[i],capital[i]};
       }
       auto cmp_cc = [](const pair<int,long long>& a, const pair<int, long long>& b){
            return a.second < b.second; 
       };
       sort(capitals.begin(),capitals.end(),cmp_cc);
       
       int current_capital = w;  
       int project_index = 0;
       for(int i=0;i<k;i++){
           while(project_index < profits.size() && capitals[project_index].second <= current_capital){
                pq.push({capitals[project_index].first,capitals[project_index].second});
                project_index++;
           }
           if(!pq.empty()){
                current_capital += pq.top().first;
                pq.pop();
           }else{
                break;
           }
       }
       return current_capital;    
    }
};