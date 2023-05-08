

// Link Of Problem

// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

// 1964. Find the Longest Valid Obstacle Course at Each Position



class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        map<int,int>mp;
        set<int>st;
        mp[obstacles[0]] = 1;
        st.insert(obstacles[0]);
        vector<int>ans = {1};
        for(int i = 1; i < obstacles.size();i++){
            auto it = st.lower(obstacles[i]);
            if(it == st.end())
        }
    }
};