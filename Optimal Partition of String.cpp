
// Link Of Problem

// https://leetcode.com/problems/optimal-partition-of-string/

// 2405. Optimal Partition of String






class Solution {
public:
    int partitionString(string s) {
        map<char,int>mp;
        int ans = 1;
        for(int i = 0 ; i < s.size();i++){
            mp[s[i]]++;
            if(mp[s[i]] == 2){
                ans++;
                mp.clear();
                mp[s[i]]++;
            }
        }
        return ans;
    }
};