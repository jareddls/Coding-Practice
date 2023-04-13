class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //if polish_notation isn't empty we can consider a rule
        //we'll only put numbers inside this
        stack<int> polish_notation;

        //edge case
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        for (size_t idx = 0; idx < tokens.size(); ++idx) {
            int first = 0;
            int second = 0;
            //whenever it's a number we push to a new stack
            if (tokens[idx] != "+" and tokens[idx] != "-" and tokens[idx] != "/" and tokens[idx] != "*") {
                polish_notation.push(stoi(tokens[idx]));
            }
            //whenever it is a symbol
            else {
                //the way this works is that we will always get the order right no matter what
                // like for 3 11 + 5 -
                //or for    3 11 5 + -
                
                /*
                in this case 3 and 11 get pushed, but deleted right away and pushed with their sum 14 and then you get the expected
                14 - 5 for 9

                for the second case you get 3 11 5 in the stack and you delete the two and compute the sum operation and are left with
                3 16; then when you do the last operation you get the correct order of 3 - 16
                */
                second = polish_notation.top();
                polish_notation.pop();
                first = polish_notation.top();
                polish_notation.pop();

                if (tokens[idx] == "+") {
                    polish_notation.push(first + second);
                }
                else if (tokens[idx] == "-") {
                    polish_notation.push(first - second);
                }
                else if (tokens[idx] == "/") {
                    polish_notation.push(first / second);
                }
                else if (tokens[idx] == "*") {
                    polish_notation.push(first * second);
                }
            }
        }
        return polish_notation.top();
    }
};