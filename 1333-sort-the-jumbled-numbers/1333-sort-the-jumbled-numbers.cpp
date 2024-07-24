class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            string num = to_string(nums[i]);
            string tonum = "";
            for (auto it : num) {
                tonum += to_string(mapping[it - '0']);
            }
            arr.push_back({stoi(tonum), nums[i]});
        }
        stable_sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        for (int i = 0; i < arr.size(); i++) {
            nums[i] = arr[i].second;
        }

        return nums;
    }
};
