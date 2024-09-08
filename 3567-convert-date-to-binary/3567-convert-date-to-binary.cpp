class Solution {
public:
    string convertDateToBinary(string date) {
        string ans = "";
        
        string year = date.substr(0, 4);  string month = date.substr(5, 2); 
        string day = date.substr(8, 2);   
        int yearInt = stoi(year);
        int monthInt = stoi(month);
        int dayInt = stoi(day);

        ans += toBinary(yearInt) + "-";   
        ans += toBinary(monthInt) + "-";  
        ans += toBinary(dayInt);          

        return ans;
    }

    string toBinary(int num) {
        string binary = bitset<32>(num).to_string();
        auto pos = binary.find('1');
        return pos == string::npos ? "0" : binary.substr(pos);
    }
};


