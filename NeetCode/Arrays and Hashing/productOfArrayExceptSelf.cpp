class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //initialize both prefix and postfix with 1
        //prefix are values to the left of the element we are not considering
        //vice versa for postfix

        //test case of [1,2,3,4]
        vector<int> prefix (1,1);
        vector<int> postfix (1,1);

        //holds our final product
        vector<int> answer;

        int prefix_product = 1;
        int postfix_product = 1;

        /*
        vector [1]

        1 * 1 = 1
        1 * 2 = 2
        2 * 3 = 6

        vector [1,1,2,6]
        */
        for (size_t idx = 0; idx < nums.size() - 1; ++idx) {
            prefix_product *= nums[idx];
            prefix.push_back(prefix_product);
        }

        /*
        vector [1]

        1 * 4 = 4
        4 * 3 = 12
        12 * 2 = 24

        vector [1,4,12,24]
        */
        for (size_t idx = nums.size() - 1; idx > 0; --idx) {
            postfix_product *= nums[idx];
            postfix.push_back(postfix_product);
        }

        /*
        product is the prefix * postfix
        so to get the actual multiplication in line
        you have to reverse the postfix so you end up with:

        1 1 2 6
        24 12 4 1

        multiplied straight on the same index:
        24 12 8 6
        */
        reverse(postfix.begin(), postfix.end());
        
        //final product calculation
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            answer.push_back(prefix[idx]*postfix[idx]);
        }

        return answer;
    }
};