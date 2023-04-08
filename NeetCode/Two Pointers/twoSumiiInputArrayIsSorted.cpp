//two pointers
//so let's think left and right
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left+1, right+1};
            }
            //since it's sorted, if we have less than the target
            //we can increment the left side, to get a larger sum
            else if (sum < target) {
                left++;
            }
            //vice versa for right
            else if (sum > target) {
                right--;
            }
        }
        //i don't think this has a reason to ever run
        return {};
    }
};