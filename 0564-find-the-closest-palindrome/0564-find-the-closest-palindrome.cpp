class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if(len == 1){
            return to_string(stoi(n)- 1);
        }

        vector<long long> cand;

        cand.push_back(pow(10, len -1) -1);
        cand.push_back(pow(10, len) +1);

        long long prefix = stoll(n.substr(0, (len+1)/2));

        for(int i = -1 ; i <=1; i++){
            string p = to_string(prefix + i);
            string candidate = p + string(p.rbegin() + (len%2), p.rend());
            cand.push_back(stoll(candidate));
        }

        long long num = stoll(n);
        long long closest = -1;

        for(long long c : cand){
            if(c == num) continue;
            if(closest == -1 || abs(c - num) < abs(closest - num) || (abs(c - num) == abs(closest - num) && c < closest)){
                closest = c;
            }
        }

        return to_string(closest);
    }
};