class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> p;
        priority_queue<int, vector<int>, greater<int>> q;
        int n = costs.size();
        
        int left = 0, right = n - 1;
        long long cost = 0;

        while (left <= right && p.size() < candidates) {
            p.push(costs[left++]);
        }
        while (left <= right && q.size() < candidates) {
            q.push(costs[right--]);
        }

        while (k--) {
            if (q.empty() || (!p.empty() && p.top() <= q.top())) {
                cost += p.top();
                p.pop();
                if (left <= right) {
                    p.push(costs[left++]);
                }
            } else {
                cost += q.top();
                q.pop();
                if (left <= right) {
                    q.push(costs[right--]);
                }
            }
        }

        return cost;
    }
};
