class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ump;
        string ans = "";

        for(int i = 0 ; i < arr.size() ; i++){
            ump[arr[i]]++;
        }

        for(int i = 0 ; i < arr.size(); i++){
            if(ump[arr[i]] == 1){
                k--;
            }
            if(k == 0){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
};