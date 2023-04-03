

// Link Of Problem

// https://leetcode.com/problems/boats-to-save-people/

// 881. Boats to Save People








class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int>st;
        for(auto it: people)st.insert(it);
        int ans = 0;
        while(!st.empty()){
            int x = limit - *prev(st.end());
            st.erase(prev(st.end()));
            auto it = st.lower_bound(x);
            if(it == st.end()){
                if(!st.empty()){
                    st.erase(prev(it));
                }
            }
            else if(it == st.begin()){
                if(*it == x)st.erase(it);
            }
            else{
                if(*it == x)st.erase(it);
                else st.erase(prev(it));
            }
            ++ans;
        }
        return ans;
    }
};