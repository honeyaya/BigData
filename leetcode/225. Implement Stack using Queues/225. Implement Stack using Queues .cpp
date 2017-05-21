class MyStack {
public:
    /** Initialize your data structure here. */
    //MyStack() {
        queue<int> q1;
        queue<int> q2;
        
    //}
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q2.push(tmp);
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 
 
