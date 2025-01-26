class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin() , courses.end(), [](const vector<int>& a, vector<int>&b){
            return a[1] < b[1];
        });

        priority_queue<int>q;
        int time = 0;
        for(auto it : courses){
            time += it[0];
            q.push(it[0]);
            if(time > it[1]){
                time -= q.top();
                q.pop();
            }
        }

        return q.size();
    }
};