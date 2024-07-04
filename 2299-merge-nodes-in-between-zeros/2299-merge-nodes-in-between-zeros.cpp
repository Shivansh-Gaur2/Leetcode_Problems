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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head -> next;
        ListNode* nextS = temp;

        while(nextS != NULL){
            int sum = 0;
            while(nextS -> val != 0){
                sum += nextS->val;
                nextS = nextS -> next;
            }

            temp-> val = sum;
            nextS = nextS -> next;
            temp-> next = nextS;
            temp = temp -> next;
        }
        return head-> next;
    }
};