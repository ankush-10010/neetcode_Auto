struct Node{
    int val;
    Node* next;
    Node(int v) : val(v) , next(nullptr) {}
};

class MyCircularQueue {
private:
    Node* head;
    Node* tail;
    int count;
    int capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        count = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool enQueue(int value) {
        if(count >= capacity){
            return false;
        }
        Node* newNode = new Node(value);
        if(count == 0){
            head = newNode;
            tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = tail->next;
            tail->next = head;
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count == 0) return false;
        //FIFO means we will remove head
        if(count == 1){
            head = nullptr;
            tail = nullptr;
            
        }else{
            Node* newHead = head->next; 
            tail->next = newHead;
            head->next = nullptr;
            head = newHead;
        }
        count--;
        return true;
    }
    
    int Front() {
        if(count == 0) return -1;
        if(head != nullptr){
            return head->val;
        }else{
            return -1;
        }
    }
    
    int Rear() {
        if(tail != nullptr){
            return tail->val;
        }else{
            return -1;
        }
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */