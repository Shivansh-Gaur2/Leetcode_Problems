class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> ump1, ump2;

        int cnt = 0;
        vector<int> ans;

        for(int i = 0 ; i < A.size(); i++)
        {
            ump1[A[i]]++;
            ump2[B[i]]++;

            if(ump1.find(B[i]) != ump1.end()){
                cnt++;
            }
            if(ump2.find(A[i]) != ump2.end() && A[i] != B[i]) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};