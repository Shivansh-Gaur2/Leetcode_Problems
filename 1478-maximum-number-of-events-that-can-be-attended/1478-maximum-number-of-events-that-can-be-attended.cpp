class Solution {
public:
static bool compare(vector<int>&a, vector<int>&b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
         set<int> st;
        for(auto i: events)
        {
            cout<<i[0]<<i[1]<<endl;
        }
        for(int i=1;i<=100000;i++)
        {
            st.insert(i);//pool of availabale days when you can attend meeting
        }
        int cnt=0;
        for(auto i:events)
        {
            int s=i[0];//start day
            int e=i[1];//end day
            auto it=st.lower_bound(s);//the first day in set that is just greater than day s
            if(it==st.end() || *it>e)//if not found or available date > end time of current evenrt
            {
                continue;
            }
            else
            {
                cnt++;
                st.erase(it);//once you use a day, u remove it from set
            }
          
        }
        return cnt;
    }
};