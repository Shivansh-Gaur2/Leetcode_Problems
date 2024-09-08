#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canChooseWithMinDiff(const vector<int>& intervals, int jumpRange, long long minDiff) {
        long long lastChosen = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (lastChosen + minDiff <= intervals[i] + jumpRange) {
                lastChosen = max(lastChosen + minDiff, (long long)intervals[i]);
            } else {
                return false;
            }
        }
        return true;
    }

    int maxPossibleScore(vector<int>& intervals, int jumpRange) {
        sort(intervals.begin(), intervals.end());
        long long lowerBound = 0, upperBound = (long long)(intervals.back() + jumpRange) - intervals[0];
        int bestScore = 0;

        while (lowerBound <= upperBound) {
            long long mid = lowerBound + (upperBound - lowerBound) / 2;
            if (canChooseWithMinDiff(intervals, jumpRange, mid)) {
                bestScore = mid;
                lowerBound = mid + 1;
            } else {
                upperBound = mid - 1;
            }
        }

        return bestScore;
    }
};
