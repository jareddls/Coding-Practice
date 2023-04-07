//current solution
class Solution {
public:
    bool isPalindrome(string s) {
        //initialize a string, so that we can store the conversion of only
        //alpha numeric values
        //isalnum (for c++)
        string only_alnum;
        string only_alnum_rev;

        //iterate through the string
        for (size_t idx = 0; idx < s.size(); ++idx) {
            if (isalnum(s[idx])) {
                only_alnum.push_back(tolower(s[idx]));
                only_alnum_rev.push_back(tolower(s[idx]));
            }
        }

        reverse(only_alnum_rev.begin(),only_alnum_rev.end());

        return only_alnum == only_alnum_rev;
    }
};


//previous solution I had
//what was I on??
class Solution {
public:

    bool isPalindrome(string s) {
    for(string::iterator i = s.begin(); i != s.end(); i++){
      if(!isalnum(s.at(i - s.begin())))
      {
          s.erase(i);
          i--;
      }
    }
  
    transform(s.begin(), s.end(), s.begin(), ::tolower);
        
    int end_counter = s.size() - 1;
    for (size_t idx = 0; idx < s.size(); ++idx){
        if (s[idx] == s[end_counter]){
            end_counter--;
            continue;
        }
        else return false;
    }
    return true;
}
    
};