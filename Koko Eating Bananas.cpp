
// Link of Problem

// https://leetcode.com/problems/koko-eating-bananas/

// 875. Koko Eating Bananas


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000007, mid = 0, ans = 0;
        while(l <=r){
            mid = (l + r) / 2;
            long long cnt = 0;
            for(auto it: piles){
                cnt += it / mid;
                cnt += (it % mid) ? 1 : 0;
            }
            if(cnt <= h){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};