
// Link Of Problem

// https://leetcode.com/problems/scramble-string/

// 87. Scramble String









class Solution {
    unordered_map<string,bool> ump;
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)return true;
        if((int)s1.size() == 1)return false;
        string oth = s1 + s2;
        if(ump.count(oth))return ump[oth];
        int n = (int)s1.size();
        for(int i = 1; i < n;i++){
            if(isScramble(s1.substr(0, i) ,s2.substr(0, i)) && isScramble(s1.substr(i) ,s2.substr(i))){
                return ump[oth] = true;
            }
            if(isScramble(s1.substr(0, i) ,s2.substr(n - i)) && isScramble(s1.substr(i) ,s2.substr(0, n - i))){
                return ump[oth] = true;
            }
        }
        return ump[oth] = false;
    }
};