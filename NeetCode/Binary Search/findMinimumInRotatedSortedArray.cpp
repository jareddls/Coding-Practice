class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int minimum = nums[(nums.size()-1) / 2];

        while (low <= high) {
            int middle = (low + high) / 2;
        
            minimum = min(nums[middle], minimum);

            if (nums[high] < nums[middle]) {
                low = middle + 1;
            }
            else if (nums[middle] < nums[high]) {
                high = middle - 1;
            }
            else {
                return minimum;
            }
        }
        return minimum;
    }
};