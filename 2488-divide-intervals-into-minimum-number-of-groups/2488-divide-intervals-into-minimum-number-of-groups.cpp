class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> q;

        for(auto it : intervals){
            int start = it[0];
            int end = it[1];

            if(!q.empty() && q.top() < start){
                q.pop();
            }
            q.push(end);
        }
        return q.size();
    }
};