class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); i++){
            arr[i] = arr[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto it : queries){
            int left = it[0];
            int right = it[1];
            if(left > 0){
                ans.push_back(arr[right] ^ arr[left-1]);
            }
            else{
                ans.push_back(arr[right]);
            }
        }

        return ans;
    }
};