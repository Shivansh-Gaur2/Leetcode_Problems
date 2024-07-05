class Solution {
public:
    string decodeString(string st){
        stack<string> s;
        stack<int> num;
        string ans = "";
        for (int i = 0; i < st.length(); i++) {
            if (isdigit(st[i])){
                int count = 0;
                while (i < st.length() && isdigit(st[i])) {
                    count = count * 10 + (st[i] - '0');
                    i++;
                }
                i--; // Move back one position to correct for loop increment
                num.push(count);
            } 
            else if (st[i] == '['){
                s.push(ans);
                ans = "";
            } 
            else if (st[i] == ']'){
                int repeatCount = num.top();
                num.pop();
                string temp = s.top();
                s.pop();
                for (int j = 0; j < repeatCount; j++) {
                    temp += ans;
                }
                ans = temp;
            } 
            else{
                ans += st[i];
            }
        }
        return ans;
    }
};
