class MyHashSet {
private:
    int numBuckets = 10000;
    vector<list<int>> buckets;

    int hash(int key){
        return key % numBuckets;
    }
public:
    // we will do this question with the concept of chaining 
    MyHashSet() {
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index = hash(key);

        if(!contains(key)){
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hash(key);

        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);

        for(int num : buckets[index]){
            if(num == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */