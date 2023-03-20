
// Link of Problem

// https://leetcode.com/problems/can-place-flowers/

// 605. Can Place Flowers





class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if(v.size() == 1)return !n || (n && !v[0]);
        int cnt = 0, idx = -1;
        if(!v[0] && !v[1])cnt = 1, idx = 2;
        else idx = 1;
        for(int i = idx; i < v.size();i++){
            if(!v[i] && !v[i - 1]){
                if(i != (int)v.size() - 1 && !v[i + 1])cnt++,i++;
                else if(i == (int)v.size() - 1)cnt++;
            }
            else if(v[i]) i++;
        }
        return (cnt >= n);
    }
};