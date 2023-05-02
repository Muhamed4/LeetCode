
// Link Of Problem

// https://leetcode.com/problems/power-of-two/

// 231. Power of Two



class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && !(n & (n - 1)));
    }
};