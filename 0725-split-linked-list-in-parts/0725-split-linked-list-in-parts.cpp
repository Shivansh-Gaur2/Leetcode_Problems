class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        int partSize = length / k;
        int extraNodes = length % k;

        vector<ListNode*> result(k, nullptr); 
        current = head;
        for (int i = 0; i < k && current; i++) {
            result[i] = current; 
            int currentPartSize = partSize + (i < extraNodes ? 1 : 0);  
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }

        return result;
    }
};
