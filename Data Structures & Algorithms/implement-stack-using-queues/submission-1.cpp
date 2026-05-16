class MyStack {
private: 
    queue<int>q_temp;
    queue<int>q_stack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q_stack.empty()){
                q_temp.push(q_stack.front());
                q_stack.pop();
            }
        q_stack.push(x);
        while(!q_temp.empty()){
            q_stack.push(q_temp.front());
            q_temp.pop();
        }
    }
    
    int pop(){
        int top_element = q_stack.front();
        q_stack.pop();
        return top_element;
    }
    
    int top() {
        return q_stack.front();
    }
    
    bool empty() {
        return q_stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */