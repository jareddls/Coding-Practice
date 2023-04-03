class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> duplicate_check;
        for (auto i : nums)
            duplicate_check[i]++;

        for(auto &idx : duplicate_check){
            if(idx.second >= 2) {
                return true;
            }
        }
        return false;
    }
};