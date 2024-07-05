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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = INT_MAX;
        int maxi = -1;
        
        vector<int> ans;

        ListNode* temp = head;
        int idx=  0;
        vector<int> idex;
        while(temp -> next && temp->next->next){
            if(temp->next->val > temp-> val && temp->next->val > temp->next->next->val){
                idex.push_back(idx+1);
            }
            else if(temp->next->val < temp-> val && temp->next->val < temp->next->next->val){
                idex.push_back(idx+1);
            }
            temp = temp->next;
            idx++;
        }

        if(idex.size() < 2){
            return {-1, -1};
        }
        for(int i = 1 ; i < idex.size(); i++){
            cout << idex[i] << " ";
            mini = min(mini, abs(idex[i] - idex[i-1]));
        }
        
        int n = idex.size();
        cout << n << endl;
        maxi = idex.back() - idex.front();
       
       ans.push_back(mini);
       ans.push_back(maxi);
        return ans;
    }
};