class Solution {
public:
    int minLength(string s) {
        while(true){
            string s1 = "AB";
            string s2 = "CD";

            int pos1 = s.find(s1);
            int pos2 = s.find(s2);

            if(pos1 == string::npos && pos2 == string::npos){
                break;
            }

            cout<< pos1 << " " << pos2 << endl;
            if(pos1 != string::npos){
                
                s = s.substr(0, pos1) + s.substr(pos1+2);
            }
            else if(pos2 != string::npos){
                s = s.substr(0, pos2) + s.substr(pos2+2);
            }

        }
        return s.size();
    }
};