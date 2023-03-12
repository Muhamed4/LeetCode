

// Link of Problem

// https://leetcode.com/problems/merge-k-sorted-lists/

// 23. Merge k Sorted Lists




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>values;
        for(int i = 0 ; i < lists.size();i++){
            ListNode* cop = lists[i];
            while(cop != nullptr){
                values.push_back(cop->val);
                cop = cop->next;
            }
        }
        sort(values.begin(), values.end());
        ListNode* root = new ListNode();
        ListNode* cop = new ListNode();
        for(int i = 0 ; i < values.size();i++){
            if(i == 0){
                root->val = values[i];
                cop = root;
            }
            else{
                ListNode* oth = new ListNode(values[i]);
                cop->next = oth;
                cop = oth;
            }
        }
        return values.size() == 0 ? nullptr : root;
    }
};