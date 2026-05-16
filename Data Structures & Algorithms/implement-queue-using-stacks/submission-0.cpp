class MyQueue {
private: 
    stack<int> s_temp;
    stack<int> s_queue;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s_queue.empty()){
            s_temp.push(s_queue.top());
            s_queue.pop();
        }
        s_queue.push(x);
        while(!s_temp.empty()){
            s_queue.push(s_temp.top());
            s_temp.pop();
        }
    }
    
    int pop() {
        int top_element = s_queue.top();
        s_queue.pop();
        return top_element;
    }
    
    int peek() {
        return s_queue.top();
    }
    
    bool empty() {
        return s_queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */