class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<int> idex;

        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                idex.push_back(i);
            }
        }

        for(int i = 0 ; i < boxes.size(); i++){
            int cnt = 0;
            for(int j = 0; j < idex.size(); j++){
                cnt += abs(i - idex[j]);
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};