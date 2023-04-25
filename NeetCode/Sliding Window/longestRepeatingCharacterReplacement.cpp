class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, temp_max = 0;
        unordered_map<char, int> occurences;
        int result = -1;

        while(right < s.size()) {
            occurences[s[right]]++;
            temp_max = max(temp_max, occurences[s[right]]);
            if((right-left+1) - temp_max > k){
                occurences[s[left]]--;
                left++;
            }
            result = max(result, (right-left+1));
            right++;   
        }
        return result;
    }
};