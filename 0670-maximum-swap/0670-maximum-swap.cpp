class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<pair<int,int>> pq;
        string n = to_string(num);
        
        for(int i = 0; i < n.size(); i++) {
            pq.push({n[i] - '0', i});
        }

        for(int i = 0; i < n.size(); i++) {
            while(!pq.empty() && pq.top().second <= i) {
                pq.pop();
            }
            if(pq.empty()) break;

            int currentDigit = n[i] - '0';
            auto top = pq.top();

            if(top.first > currentDigit) {
                swap(n[i], n[top.second]);
                break;
            }
        }

        return stoi(n);
    }
};
