class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_dict = {}
        for chr in s:
            s_dict[chr] = s_dict.get(chr,0) + 1
        
        t_dict = {}
        for chr2 in t:
            t_dict[chr2] = t_dict.get(chr2,0) + 1

        return s_dict == t_dict