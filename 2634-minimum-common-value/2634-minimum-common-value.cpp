class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i < nums1.size(); i++){
            int ind = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if(ind >= nums2.size()){
                continue;
            }
            else if(nums2[ind] == nums1[i]){
                return nums1[i];
            }
            // cout << lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() << endl;
        }
        return -1;
    }
};