class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> s_map = {};
        std::map<char, int> t_map = {};

        for (auto &chr: s){
            s_map[chr]++;
        }

        for (auto &chr2: t){
            t_map[chr2]++;
        }

        return s_map == t_map;
        
    }
};