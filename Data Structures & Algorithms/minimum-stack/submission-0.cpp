class MinStack {
public:
    vector<int> vec;
    MinStack() {
    }
    
    void push(int val) {
        vec.push_back(val);
    }
    bool isEmpty(){
        return vec.size()==0;
    }
    void pop() {
        if(isEmpty()){
            return;
        }
        vec.pop_back();
    }
    
    int top() {
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }
    
    int getMin() {
        int minVal=INT_MAX;
        for(int i=0;i<vec.size();i++){
            minVal=min(minVal,vec[i]);
        }
        return minVal;
    }
};
