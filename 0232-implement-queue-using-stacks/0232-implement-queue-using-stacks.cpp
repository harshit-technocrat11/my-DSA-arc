class MyQueue {
private: 
    stack<int> i; //input
    stack<int> o; //output
public:
    MyQueue() {
        
    }
    
    void transfer(){
        while(!i.empty()){
            o.push(i.top());
            i.pop();
        }
    }

    void push(int x) {
        i.push(x);
    }    
    int pop() {
        if (!o.empty()){
            int a = o.top();
            o.pop();

            return a;
        } 

        else {
            transfer();
            int a = o.top();
            o.pop();

            return a;
        }
        return -1;
    }
    
    int peek() {
        if (!o.empty()) return o.top();

        else {
            transfer();
            return o.top();
        }
        return -1;
        
    }
    
    bool empty() {
        return i.empty() && o.empty();
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