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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* oddStart = head->next;

        while(odd && odd->next){
            even->next = even->next->next;
            odd->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }
        even->next = oddStart;
        return head;
    }
};