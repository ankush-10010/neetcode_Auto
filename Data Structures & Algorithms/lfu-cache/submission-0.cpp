class LFUCache {
private:
    struct Node{
        int key;
        int value;
        int freq;
    };

    int capacity;
    int minfreq;

    unordered_map<int,list<Node>:: iterator> keyMap;
    unordered_map<int,list<Node>> freqMap;

    void updateFreq(int key){
        auto nodeitr = keyMap[key];
        Node node = *nodeitr;

        // node.freq , node.key
        freqMap[node.freq].erase(nodeitr);
        // freqMap was a doubly linked list , to erase it we must need an 
        // iterator pointing to that specific element 

        if(freqMap[node.freq].empty() && minfreq == node.freq){
            minfreq++;
        }

        node.freq++;
        freqMap[node.freq].push_front(node);

        keyMap[key] = freqMap[node.freq].begin();
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minfreq = 0;
    }
    
    int get(int key) {
        if(keyMap.find(key) == keyMap.end()){
            return -1;
        }
        updateFreq(key);
        return keyMap[key]->value;
    }
    
    void put(int key, int value) {
       if(capacity == 0) return;

       if(keyMap.find(key) != keyMap.end()){
            keyMap[key]->value = value;
            updateFreq(key);
            return;
       }

       if(keyMap.size() == capacity){
            Node delNode = freqMap[minfreq].back();
            keyMap.erase(delNode.key);
            freqMap[minfreq].pop_back();
       }
       Node newNode = {key, value, 1}; 
       freqMap[1].push_front(newNode);
        keyMap[key] = freqMap[1].begin();
        minfreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */