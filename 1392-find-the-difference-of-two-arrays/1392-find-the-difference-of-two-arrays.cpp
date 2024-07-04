class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int>mp1,mp2;
        for(auto it : nums1)    mp1[it]++;
        for(auto it : nums2)    mp2[it]++;
        vector<int>tempans;
        for(auto it: mp1)
        {
            if(mp2.find(it.first)==mp2.end()) tempans.emplace_back(it.first);
        }
        ans.emplace_back(tempans);
        tempans.clear();
        for(auto it: mp2)
        {
            if(mp1.find(it.first)==mp1.end()) tempans.emplace_back(it.first);
        }
        ans.emplace_back(tempans);
        return ans;
    }
};