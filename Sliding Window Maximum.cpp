

// Link Of Problem

// https://leetcode.com/problems/sliding-window-maximum/

// 239. Sliding Window Maximum




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>st;
        for(int i = 0; i < k;i++){
            st.insert(nums[i]);
        }
        ans.push_back(*prev(st.end()));
        for(int i = k; i < (int)nums.size();i++){
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            ans.push_back(*prev(st.end()));
        }
        return ans;
    }
};