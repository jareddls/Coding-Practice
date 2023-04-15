class Solution {
public:
    stack<char> parentheses;
    vector<string> final_result;    

    vector<string> generateParenthesis(int n) {
        //recursion
        //closed has to be less than open in order to place a closing parentheses
        //we can say the parentheses are valid when both open and closed are equal to n
        backtrack(0, 0, n);

        return final_result;

    }

    void backtrack(int open, int closed, int n) {
        if (open == n && closed == n) {
            final_result.push_back(getValid(parentheses));
        }

        if (open < n) {
            parentheses.push('(');
            backtrack(open + 1, closed, n);
            parentheses.pop();
        }

        if (closed < open) {
            parentheses.push(')');
            backtrack(open, closed + 1, n);
            parentheses.pop();
        }
    }

    string getValid(stack<char> parentheses) {
        stack<char> temp = parentheses;
        string valid = "";

        while (!temp.empty()) {
            valid += temp.top();
            temp.pop();
        }
        
        reverse(valid.begin(), valid.end());
        return valid;
    } 

};