class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);
         int mod = 1e9 + 7;

        for (auto& it : requests) {
            int left = it[0];
            int right = it[1];
            arr[left]++;
            if (right + 1 < n) {
                arr[right + 1]--;
            }
        }

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        arr.pop_back();

        sort(arr.rbegin(), arr.rend());
        sort(nums.rbegin(), nums.rend());

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ((long long)nums[i] * arr[i]);
        }

        return sum % mod;
    }
};
