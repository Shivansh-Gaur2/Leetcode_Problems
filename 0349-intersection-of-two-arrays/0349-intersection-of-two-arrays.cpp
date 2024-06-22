class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        unordered_map<int, int> ump;
        for(int i =  0 ; i < nums1.size(); i++){
            ump[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(ump.find(nums2[i]) != ump.end()){
                ans.push_back(nums2[i]);
                ump.erase(nums2[i]);
            }
        }

        return ans;
    }
};