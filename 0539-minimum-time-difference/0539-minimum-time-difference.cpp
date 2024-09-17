class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        int n = minutes.size();
        for (int i = 1; i < n; ++i) {
            int timeDiff = minutes[i] - minutes[i - 1];
            minDiff = min(minDiff, timeDiff);
        }
        int wrapAroundDiff = (1440 - minutes[n - 1] + minutes[0]);
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};
