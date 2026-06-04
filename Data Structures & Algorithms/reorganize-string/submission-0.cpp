class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
        }

        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.push({freq[i],i+'a'});
            }
        }

        string result = "";
        pair<int,int> prev = {-1,'#'};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            result += curr.second;
            curr.first--;
            if(prev.first > 0){
                pq.push(prev);
            }
            prev = curr;
        }
        if(result.length() != s.length()){
            return "";
        }
        return result;
    }
};