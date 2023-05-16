
// Link Of Problem

// https://leetcode.com/problems/swap-nodes-in-pairs/

// 24. Swap Nodes in Pairs



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
    ListNode* Swap(ListNode* head){
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* temp = head->next;
        head->next = Swap(temp->next);
        temp->next = head;
        return temp;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return Swap(head);
    }
};