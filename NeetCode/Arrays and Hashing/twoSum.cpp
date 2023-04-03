class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create possible sums array

        vector<int> nums_sum;
        vector<pair<int,int>> indices;

        // 0,1 | 0,2 | 0,3 | 0,4 | 1,2 | 1,3 | 2,3
        // track it with an index counter for the nums_sum array
        // double for loop
        int idx_ctr = 0;
        bool flag = true;
        for (size_t i = 0; i < nums.size()-1; ++i) {
            for (size_t j = i+1; j < nums.size(); ++j) {
                nums_sum.push_back(nums[i] + nums[j]);
                indices.push_back(make_pair(i,j));
                if ((nums[i] + nums[j]) == target) {
                    flag = false;
                }
                else if((nums[i] + nums[j]) != target && flag) {
                    idx_ctr++;
                }
                
            }
        }

        vector<int> finalValue;
        finalValue.push_back(indices[idx_ctr].first);
        finalValue.push_back(indices[idx_ctr].second);

        return finalValue;
    }
};