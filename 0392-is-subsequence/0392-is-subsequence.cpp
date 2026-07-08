class Solution {
public:
    bool isSubsequence(string s, string t) {

        if(s.empty()) return 1;
        char ch = s[0];

        for(int i = 0; i < t.length(); i++)  if(ch == t[i]) s.erase(0,1), ch = s[0]; 
        
        return s.empty();
    }
};