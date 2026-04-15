class LRUCache {
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node *dummyHead;
    Node *dummyTail;
    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void toAddNode(Node* node){
        Node* temp = dummyHead->next;
        dummyHead->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = dummyHead;
    }
public:
    /* using hashmaps + Double linked list 
    hashmaps doesnt just store the integer value , its
    value is direct pointer to the exact node inside the Doubly
    linked list , lets say we call get(2) , the hashmap instantly 
    gives the exact node object from the doubly linked list in O(1) */
    LRUCache(int capacity) {
        cap = capacity;
        dummyHead = new Node(-1,-1);
        dummyTail = new Node(-1,-1);  

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;  
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* mRUnode = cache[key];
            deleteNode(mRUnode);
            // Node* prev = mRUnode->prev;
            // Node* next = mRUnode->next;
            // prev->next = next;
            // next->prev = prev;
            toAddNode(mRUnode);
            // Node* temp = dummyHead->next;
            // dummyHead->next = mRUnode;
            // temp->prev = mRUnode;
            // mRUnode->next = temp;
            // mRUnode->prev = dummyHead;
            return mRUnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // two cases there can be , first is the key already exists in the cache 
        // second is key doesnt exist in the cache 
        if(cache.find(key) != cache.end()){
            Node* existingNode = cache[key];
            existingNode->val = value;

            deleteNode(existingNode);
            toAddNode(existingNode);
        }else{
            Node* newNode = new Node(key,value);
            cache[key] = newNode;
            toAddNode(newNode);

            if(cache.size()>cap){
                Node* lruNode = dummyTail->prev;
                cache.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode;
            }
        }
    }
};
