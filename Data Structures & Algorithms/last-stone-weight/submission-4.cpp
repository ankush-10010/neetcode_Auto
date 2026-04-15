class Solution {
public:
    priority_queue<int,vector<int>> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if((temp1-temp2) != 0){
                pq.push(temp1-temp2);
            }
        }
        if(pq.size()==0){
            return 0;
        }else{
            return pq.top();
        }
    }
};
