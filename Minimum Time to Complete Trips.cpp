
// Link of Problem

// https://leetcode.com/problems/minimum-time-to-complete-trips/

// 2187. Minimum Time to Complete Trips



class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e14, mid = 0, ans = 0;
        while(l <= r){
            mid = (l + r) / 2;
            long long res = 0;
            for(auto it: time)res += (mid / it);
            if(res >= totalTrips){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};