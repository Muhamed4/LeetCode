
// Link Of Problem

// https://leetcode.com/problems/valid-parentheses/

// 20. Valid Parentheses



class Solution {
    bool valid(char a, char b){
        return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
    }
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(valid(st.top(), s[i]))st.pop();
                else st.push(s[i]);
            }
        }
        return st.empty();
    }
};