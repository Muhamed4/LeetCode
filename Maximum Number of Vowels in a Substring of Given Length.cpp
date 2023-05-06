
// Link Of Problem

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

// 1456. Maximum Number of Vowels in a Substring of Given Length








class Solution {
public:
    bool Vowels(char s){
        return(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
    }
    int maxVowels(string s, int k) {
        int cnt = 0;
        int n = (int)s.size();
        for(int i = 0 ; i < k;i++){
            if(Vowels(s[i]))++cnt;
        }
        int ans = cnt;
        for(int i = k;i < n;i++){
            if(Vowels(s[i - k]))--cnt;
            if(Vowels(s[i]))++cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};