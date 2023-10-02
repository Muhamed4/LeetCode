

// Link of Problem

// https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=daily-question&envId=2023-10-01

// 557. Reverse Words in a String III




class Solution {
public:
    string reverseWords(string& s) {
        int sz = (int)s.size();
        int idx = -1;
        while(idx < sz){
            ++idx;
            int newidx = idx;
            while(newidx < sz && s[newidx] != ' ')++newidx;
            reverse(s.begin() + idx, s.begin() + newidx);
            idx = newidx;
        }
        return s;
    }
};