class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack<char> st;

        int poi = 0;
        while(poi < s.size()){
            if(s[poi] != '*'){
                st.push(s[poi]);
            }
            else{
                st.pop();
            }
            poi++;
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};