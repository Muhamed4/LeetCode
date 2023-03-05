
// Link of Problem
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/


class Solution {
public:
    long long countSubarrays(vector<int>& v, int x, int y) {
        stack<int>st1, st2;
        int n = (int)v.size();
        vector<int>left(n), right(n);
        vector<int>oleft(n), oright(n);
        long long ans = 0;
        for(int i = n - 1; i >= 0;i--){
            if(st1.empty()){
                st1.push(i);
                left[i] = n;
            }
            else{
                while(!st1.empty() && v[i] <= v[st1.top()])st1.pop();
                if(st1.empty())left[i] = n;
                else left[i] = st1.top();
                st1.push(i);
            }
            if(st2.empty()){
                st2.push(i);
                right[i] = n;
            }
            else{
                while(!st2.empty() && v[i] >= v[st2.top()])st2.pop();
                if(st2.empty())right[i] = n;
                else right[i] = st2.top();
                st2.push(i);
            }
        }
        st1 = st2 = stack<int>();
        for(int i = 0 ; i < n;i++){
            if(st1.empty()){
                st1.push(i);
                oleft[i] = -1;
            }
            else{
                while(!st1.empty() && v[i] < v[st1.top()])st1.pop();
                if(st1.empty())oleft[i] = -1;
                else oleft[i] = st1.top();
                st1.push(i);
            }
            if(st2.empty()){
                st2.push(i);
                oright[i] = -1;
            }
            else{
                while(!st2.empty() && v[i] > v[st2.top()])st2.pop();
                if(st2.empty())oright[i] = -1;
                else oright[i] = st2.top();
                st2.push(i);
            }
        }
        set<int>mink, maxk;
        long long cnt = 0;
        for(int i = 0 ; i < n;i++){
            if(v[i] == x)mink.insert(i), cnt++;
            else if(v[i] == y)maxk.insert(i);
        }
        if(x == y){
            return cnt * (cnt + 1) / 2;
        }
        for(auto it : mink){
            auto itt = maxk.upper_bound(it);
            if(itt == maxk.end())break;
            long long cnt1 = min(max(0, it - oleft[it]), max(0, it - oright[*itt]));
            long long cnt2 = min(max(0, left[it] - *itt), max(0, right[*itt] - *itt));
            ans += (cnt1 * cnt2);
        }
        for(auto it : maxk){
            auto itt = mink.upper_bound(it);
            if(itt == mink.end())break;
            long long cnt1 = min(max(0, it - oright[it]), max(0,it - oleft[*itt]));
            long long cnt2 = min(max(0, left[*itt] - *itt), max(0, right[it] - *itt));
            ans += (cnt1 * cnt2);
        }
        // 35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913
        // 35054
        // 945315

        return ans;
    }
};