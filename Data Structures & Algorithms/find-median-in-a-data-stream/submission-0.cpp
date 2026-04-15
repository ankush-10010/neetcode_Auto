class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>pq; //min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {  
        pq.push(num);
    }
    
    double findMedian() {
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        int n = result.size();
        int temp1 = result[(n+1)/2 - 1];
        int temp2 = result[(n+2)/2 - 1];
        for(int r : result){
            pq.push(r);
        }
        return (temp1+temp2)/2.0;
    }
};
