
// Link of Problem

//https://leetcode.com/problems/kth-missing-positive-number/

// 1539. Kth Missing Positive Number


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>all;
        map<int,int>mp;
        for(auto it : arr)mp[it]++;
        for(int i = 1; i <= 2000;i++){
            if(!mp.count(i))all.push_back(i);
        }
        return all[k - 1];
    }
};