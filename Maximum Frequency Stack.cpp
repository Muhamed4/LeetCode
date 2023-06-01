

// Link Of Problem

// https://leetcode.com/problems/maximum-frequency-stack/

// 895. Maximum Frequency Stack





class FreqStack {
    unordered_map<int,int>mp;
    unordered_map<int,stack<int>> um;
    int mx;

public:
    FreqStack() {
        mx = 0;
    }
    
    void push(int val) {
        mp[val]++;
        mx = max(mx , mp[val]);
        um[mp[val]].push(val);
    }
    
    int pop() {
        int ans = um[mx].top();
        um[mx].pop();
        mp[ans]--;
        if(um[mx].size() == 0)--mx;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */