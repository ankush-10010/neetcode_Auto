class FreqStack {
private:
    unordered_map<int, int> freq;               // Tracks frequency of each element
    unordered_map<int, stack<int>> groupStacks; // Maps a frequency to a stack of elements
    int maxFreq;                                // Tracks the current maximum frequency

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        // 1. Update the frequency of the value
        freq[val]++;
        int currentFreq = freq[val];
        
        // 2. Update maxFreq if this element set a new record
        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
        }
        
        // 3. Push the value into the stack corresponding to its current frequency
        groupStacks[currentFreq].push(val);
    }
    
    int pop() {
        // 1. Get the most frequent element from the top of the maxFreq stack
        int val = groupStacks[maxFreq].top();
        
        // 2. Remove it from that stack
        groupStacks[maxFreq].pop();
        
        // 3. Decrease its overall frequency
        freq[val]--;
        
        // 4. If the maxFreq stack is now empty, lower the maxFreq by 1
        // (Because we know the stack for maxFreq - 1 is guaranteed to have elements)
        if (groupStacks[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};