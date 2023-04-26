/***************************************************************************
 * This file is for the 567. Permutation in String in LeetCode.
 * https://leetcode.com/problems/permutation-in-string/description/
 * 
 * Not sure if my problem correctly implements Sliding Window algorithm,
 * however this is the way I thought of it, to be technically O(n).
 * I did not use the NeetCode video to help solve this problem this time!
 * So I'm glad I was able to figure it out with the use of maps.
 * 
 * Extra notes:
 * I compared the maps to see if they were of equal value, because if they
 * were, then that means it was a valid permutation.
 * I stored the permutation we're looking for in the amount map, and
 * I stored the starting window we're looking at into s2_amt.
 * We go through the check now of sliding the window, where 
 * if the map isn't equal to the other one, we remove the value of where
 * the left pointer was looking at, then move it one forward, and then for
 * the right we move it one first, THEN add the value into the map.
 * 
 * The order here matters, as such:
 * s2_amt[s2[left]]-- -> left++ -> right ++ -> s2_amt[s2[right]]++
 * 
 * The reason is if for example:
 * 
 * s1 = 'ab'
 * s2 = 'bcdbak'
 * 
 * On first iteration:
 * amount = 'ab'
 * s2_amt = 'bc'
 * 
 * These don't equal, so what we're going to do is:
 * remove 'b' from s2_amt: (s2_amt = 'c') then move the right pointer and add
 * it, so (s2_amt = 'cd')
 * 
 * If we did it any other order, like moving left pointer before deleting
 * we'd end up removing 'c' from s2_amt and having a resulting string like
 * 'bd'
****************************************************************************/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.size()-1;
        unordered_map<char, int> amount;
        unordered_map<char, int> s2_amt;

        if (s2.size() < s1.size()) {
            return false;
        }

        for (int idx = 0; idx < s1.size(); ++idx){
            amount[s1[idx]]++;
        }

         for (int idx = 0; idx < s1.size(); ++idx) {
            s2_amt[s2[idx]]++;
        }

        while (right < s2.size()) {
            if(amount == s2_amt) {
                return true;
            }

            s2_amt[s2[left]]--;

            if (s2_amt[s2[left]] == 0) {
                s2_amt.erase(s2[left]);
            }

            left++;

            right++;
            s2_amt[s2[right]]++;
        }

        return false;

    }
};