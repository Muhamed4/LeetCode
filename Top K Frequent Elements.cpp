
// Link Of Problem

// https://leetcode.com/problems/top-k-frequent-elements/

// 347. Top K Frequent Elements




class Solution {
    int frq[20004]{0};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto &it: nums){
            frq[it + 10000]++;
        }
        priority_queue<pair<int,int>>big;
        for(int i = 1; i <= 20000;i++){
            if(frq[i])big.push({frq[i], i});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(big.top().second - 10000);
            big.pop();
        }
        return ans;
    }
};