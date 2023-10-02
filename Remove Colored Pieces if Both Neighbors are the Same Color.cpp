

// Link of Problem

// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/?envType=daily-question&envId=2023-10-02

// 2038. Remove Colored Pieces if Both Neighbors are the Same Color






class Solution {
public:
    bool winnerOfGame(string& colors) {
        int A = 0, B = 0;
        int cnt1 = 0, cnt2 = 0;
        for(auto &it: colors){
            if(it == 'A'){
                B += max(0, cnt2 - 2);
                cnt2 = 0;
                ++cnt1;
            }
            else{
                A += max(0, cnt1 - 2);
                cnt1 = 0;
                ++cnt2;
            }
        }
        A += max(0, cnt1 - 2);
        B += max(0, cnt2 - 2);
        return (A > B);
    }
};

// A B B B B B B B A A A