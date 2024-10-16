class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        // Push only non-zero counts into the priority queue
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();

            // If the last two characters are the same as the current character
            if (ans.size() >= 2 && ans.back() == char1 && ans[ans.size() - 2] == char1) {
                if (pq.empty()) break;  // If there's no other character to choose, break

                auto [count2, char2] = pq.top();
                pq.pop();

                // Use the second most frequent character instead
                ans += char2;
                if (--count2 > 0) pq.push({count2, char2});  // Decrease the count and push it back

                pq.push({count1, char1});  // Push the first character back to be used later
            } else {
                // Use the most frequent character
                ans += char1;
                if (--count1 > 0) pq.push({count1, char1});  // Decrease the count and push it back
            }
        }

        return ans;
    }
};
