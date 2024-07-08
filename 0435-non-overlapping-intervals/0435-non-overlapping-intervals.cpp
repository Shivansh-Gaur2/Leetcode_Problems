class Solution {
public:
static bool compare(vector<int>&a, vector<int>&b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        int cnt = 1;
        int end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= end){
                cnt++;
                end = intervals[i][1];
            }
        }
        return n - cnt;
    }
};