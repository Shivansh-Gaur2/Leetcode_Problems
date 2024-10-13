class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }

        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long maxScore = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i].second;
            minHeap.push(arr[i].second);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                long long currentScore = sum * arr[i].first;
                maxScore = max(maxScore, currentScore);
            }
        }

        return maxScore;
    }
};
