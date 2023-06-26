
// Link Of Problem

// https://leetcode.com/problems/total-cost-to-hire-k-workers/

// 2462. Total Cost to Hire K Workers





class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0, j = (int)costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        long long ans = 0;
        while(k--){
            while(left.size() < candidates && i <= j){
                left.push(costs[i]);
                ++i;
            }
            while(right.size() < candidates && i <= j){
                right.push(costs[j]);
                --j;
            }
            int mnleft = left.empty() ? INT_MAX : left.top();
            int mnright = right.empty() ? INT_MAX : right.top();
            if(mnleft <= mnright){
                ans += mnleft;
                left.pop();
            }
            else{
                ans += mnright;
                right.pop();
            }
        }
        return ans;
    }
};


// [18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75]