//not sure if I defeated the whole purpose of the min stack
//but I didn't define anything in the MinStack constructor
//and instead I just defined two stacks for the problem

class MinStack {
    
public:
    stack<int> first_stack;
    stack<int> min_stack;

    MinStack() {

    }


    //we had to push a value into min_stack
    //only when we find something lower
    //so if the value we are looking to push
    //is lower than the top of the min_stack
    //then we have found a new minimum
    void push(int val) {
        first_stack.push(val);

        if (min_stack.empty()) {
            min_stack.push(val);
        }
        else if (min_stack.top() >= val) {
            min_stack.push(val);
        }
    }
    
    //pop is special here in the sense that
    //we will only pop the min_stack when we find
    //the value that is being popped from the first_stack 
    //matches what is on top of the min_stack

    //otherwise, what we are popping wouldn't make sense
    void pop() {
        if (min_stack.top() == first_stack.top()) {
            min_stack.pop();
        }
        first_stack.pop();
        
    }
    
    int top() {
        return first_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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