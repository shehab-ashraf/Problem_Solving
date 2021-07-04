/***************************************************************************************************
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
   1) i used 1st vector "vector<int> stack" to push i it and pop from it and take from it top
   2) i used 2end vector "vector<int> min_stack" to return minimum element (update it in evrey pushing by the minimum)

 * Consider each node in the stack having a minimum value
 ***************************************************************************************************/
class MinStack {
private:
    vector<int> stack;
    vector<int> min_stack;
    
public:

     MinStack() {}

    
    void push(int val) {
        if(!stack.size()){
            stack.push_back(val);
            min_stack.push_back(val);
        }else{
            stack.push_back(val);
            min_stack.push_back(min(val,min_stack.back()));
        }
        
    }
    
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
    }
    
    
    int top() {
        return stack.back();    
    }
    
    
    int getMin() {
        return min_stack.back();
    }
    
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
