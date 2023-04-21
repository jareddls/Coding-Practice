class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while (low <= high) {
            int middle = (low + high) / 2;

            if (nums[middle] == target) {
                return middle;
            }
            else if(nums[low] <= nums[middle]) {
                if (target > nums[middle] || target < nums[low]) {
                    low = middle + 1;
                }
                else {
                    high = middle - 1;
                }
            }
            else {
                if (target < nums[middle] || target > nums[high]) {
                    high = middle - 1;
                }
                else {
                    low = middle + 1;
                }
            }
        }

        return -1;
    }
};