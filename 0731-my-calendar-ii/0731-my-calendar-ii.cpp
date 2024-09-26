class MyCalendarTwo {
public:
vector<pair<int, int>> arr;
vector<pair<int,int>> over;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : over){
            if(max(start, it.first) < min(end, it.second)){
                return false;
            }
        }

        for(auto it : arr){
            int overStart = max(start , it.first);
            int overEnd = min(end, it.second);
            if(overStart < overEnd){
                over.push_back({overStart, overEnd});
            }
        }

        arr.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */