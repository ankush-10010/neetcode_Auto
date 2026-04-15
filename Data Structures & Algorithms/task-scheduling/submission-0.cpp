class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int> frequency ; //char and its freq
        for(char task : tasks){
            frequency[task]++;
        } // now we have frequency of each character in the tasks
        // should i go for the most frequency first , make a pq based on frequency and maxHeap
        
        priority_queue<int> pq;
        for(auto &entry : frequency){
            pq.push(entry.second);
        }
        // now we have a priority queue whose top element is with maximum frequency
        // there will be atleast (n)*(freq-1)+freq qno of cpu cycles there
        /*
        the sequence is like , suppose X have most freq and its 4 and n=2
        x->idle->idle->x->idle->idle->x->idle->idle->x
        now we have to check if the other elements can fit here in the idle part
        without violating the rules
        we have basically n*freq-1 times idle here
        */
        int time = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;

            while(cycle > 0 && !pq.empty()){
                int f = pq.top();
                pq.pop();
                if(f-1>0){
                    temp.push_back(f-1);
                }
                time++;
                cycle--;
            }

            for(int t : temp){
                pq.push(t);
            }

            if(!pq.empty()){
                time += cycle;
            }
        }
        return time;
    }
};
