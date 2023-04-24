class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int output = 0;
        unordered_set<char> set;

        int left = 0, right = 0;

        while (right < s.size()) {
            //if find gets to the end without finding the character
            //we insert it to the set and move the right pointer
            //however if we find one then we will erase the left pointer
            //and increment by one
            if (set.find(s[right]) == set.end()) {
                set.insert(s[right]);
                right++;
                output = max(output, right - left);
            } else {
                set.erase(s[left]);
                left++;
            }
        }
        return output;
    }
};