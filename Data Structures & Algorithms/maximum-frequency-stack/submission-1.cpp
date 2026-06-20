class FreqStack {
private:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>st;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int currFreq = freq[val];
        if(currFreq > maxfreq){
            maxfreq = currFreq;
        }
        st[currFreq].push(val);
    }
    
    int pop() {
        int val = st[maxfreq].top();
        st[maxfreq].pop();
        freq[val]--;
        if(st[maxfreq].empty()){
            maxfreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */