class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //one way to think about it is if it's an anagram, we can sort the letters
        //and they should come out to be the same

        //we make a hashmap of string and vector of strings
        map<string, vector<string>> anagram_map;

        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            //pushes the actual strings with the key like "aet" for eat and tea
            anagram_map[key].push_back(s);
        } 
        
        //now we create a vector of vector<string> so that we can store those values
        vector<vector<string>> grouped_anagrams;

        for (auto &a : anagram_map) {
            grouped_anagrams.push_back(a.second);
        }

        return grouped_anagrams;
    }
};