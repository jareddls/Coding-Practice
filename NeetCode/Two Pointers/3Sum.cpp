//possibly review
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       

        //similar to two sum so sort so we know when to decrease/increase left or right pointer
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution_set;
        //i remember a problem like this in compilers lol
        
        //indices cannot be the same!
        //(i != j)
        //(i != k)
        //(j != k)

        //sum has to be equal to 0
        //nums[i] + nums[j] + nums[k] == 0

        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if ((idx > 0 ) && (nums[idx] == nums[idx-1])) {
                continue;
            } 
            int left = idx + 1;
            int right = nums.size()-1;

            while (left < right) {
            int three_sum = nums[idx] + nums[left] + nums[right];
                if (three_sum < 0) {
                    left++;
                }
                else if (three_sum > 0) {
                    right--;
                }
                else {
                    solution_set.push_back({nums[idx],nums[left],nums[right]});
                    left++;
                    while (nums[left] == nums[left-1] and (left < right)) {
                        left++;
                    }
                }
            }

        }
        return solution_set;
    }
};