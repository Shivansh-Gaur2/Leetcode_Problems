class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]]++;
        }

        while (head && ump.find(head->val) != ump.end()) {
            head = head->next;
        }

        if (!head) return nullptr;

        ListNode* temp = head;
        
        while (temp && temp->next) {
            if (ump.find(temp->next->val) != ump.end()) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
