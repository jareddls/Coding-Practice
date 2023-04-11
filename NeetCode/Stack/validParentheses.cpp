class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        //if stack is odd just return false because
        //there would be a parentheses missing its counterpart
        if (s.size() % 2 == 1) {
            return false;
        }

        for(auto idx : s) {
            //push opening parentheses
            if(idx =='(' or idx =='{' or idx=='[') {
                parentheses.push(idx);   
            }
            else {
                //if closing parentheses check if the top of the stack
                //is equal the the element at which we are looking
                //if we get to this conditional, the parentheses have to be
                //a closing one
                if(parentheses.empty() || 
                (parentheses.top()=='(' && idx != ')') || 
                (parentheses.top()=='{' && idx != '}') || 
                (parentheses.top()=='[' && idx !=']')) {
                    return false;
                }

                parentheses.pop();  
            }   
        }

        //stack should be empty now because we also have the odd check to return false;
        //however in the case it is even and it isn't empty because it's all opening parentheses
        //we should just check the validity of the stack and whether it is empty or not
        return parentheses.empty();
    }
};