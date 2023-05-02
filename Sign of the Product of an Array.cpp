
// Link of Problem

// https://leetcode.com/problems/sign-of-the-product-of-an-array/

// 1822. Sign of the Product of an Array




class Solution {
public:
    int arraySign(vector<int>& nums) {
        int z = 0, n = 0;
        for(auto it: nums){
            z |= (it == 0);
            if(it < 0)n++;
        }
        if(z)return 0;
        else if(n & 1)return -1;
        return 1;
    }
};