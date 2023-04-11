
// Link Of Problem

// https://leetcode.com/problems/removing-stars-from-a-string/

// 2390. Removing Stars From a String




class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == '*')res.pop_back();
            else res += s[i];
        }
        return res;
    }
};