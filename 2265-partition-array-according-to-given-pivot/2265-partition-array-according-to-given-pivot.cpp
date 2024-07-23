class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser;
        vector<int> greater;
        vector<int> same;

        for(int i= 0 ; i < nums.size(); i++){
            if(nums[i] < pivot){
                lesser.push_back(nums[i]);
            }
            else if(nums[i] > pivot){
                greater.push_back(nums[i]);
            }
            else{
                same.push_back(nums[i]);
            }
        }
        nums = {};
        for(int i= 0; i < lesser.size() ; i++){
            nums.push_back(lesser[i]);
        }
        for(int i = 0 ; i < same.size(); i++){
            nums.push_back(same[i]);
        }
        for(int i =0 ; i < greater.size();i++){
            nums.push_back(greater[i]);
        }
        return nums;
    }
};