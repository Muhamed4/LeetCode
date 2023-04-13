
// Link Of Problem

// https://leetcode.com/problems/validate-stack-sequences/

// 946. Validate Stack Sequences


class Solution {

public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st1,st2;
        for(int i = (int)popped.size() - 1;i >= 0;i--)st2.push(popped[i]);
        for(int i = 0 ; i < (int)pushed.size();i++){
            st1.push(pushed[i]);
            while(!st1.empty() && !st2.empty() && st1.top() == st2.top())st1.pop(), st2.pop();
        }
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top())st1.pop(), st2.pop();
        return(st1.empty() && st2.empty());
    }
};