class MyQueue {
public:
    /** Initialize your data structure here. */
        std::stack<int> st1;
        std::stack<int> st2;
    MyQueue() {
    }
 
    
    /** Push element x to the back of queue. */
    // O(n) time | O(n) space
    void push(int x) {
        if(st1.empty()){
            st1.push(x);
        }else{
            while(!st1.empty()){
                int y = st1.top();
                st1.pop();
                st2.push(y);
            }
            st1.push(x);
            while(!st2.empty()){
                int y = st2.top();
                st2.pop();
                st1.push(y);
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    // O(1) time | O(1) space
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    /** Get the front element. */
    // O(1) time | O(1) space
    int peek() {
        return st1.top();
    }
    
    /** Returns whether the queue is empty. */
    // O(1) time | O(1) space
    bool empty() {
        return st1.empty();
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
