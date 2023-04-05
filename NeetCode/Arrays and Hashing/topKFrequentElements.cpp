//next time use priority queue
//learn priority queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //count the freq elements
        map<int, int> freq_element;

        //fill out the map with how much times the element shows up
        for (auto &idx : nums) {
            freq_element[idx]++;
        }

        vector<pair<int, int>> sorted_freq(freq_element.begin(), freq_element.end());

        sort(sorted_freq.begin(), sorted_freq.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });

        vector<int> all_numbers_shown;
        for (const auto& pair : sorted_freq) {
            all_numbers_shown.push_back(pair.first);
        }

        //size of all_numbers_shown minus k to get how much we pop
        int not_frequent_sum = all_numbers_shown.size() - k;

        for (size_t idx = 0; idx < not_frequent_sum; ++idx) {
            all_numbers_shown.pop_back();
        }

        return all_numbers_shown;
    }
};