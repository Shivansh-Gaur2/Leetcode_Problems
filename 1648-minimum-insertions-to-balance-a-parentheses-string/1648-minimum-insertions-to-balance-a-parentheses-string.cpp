class Solution {
public:
     int minInsertions(string s) {
        if(s.size() == 0) return 0;
        int stack = 0;
        int invalidRight = 0;
        
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            
            if(ch == '(') stack++;
            else {
                if(i+1 == s.size() || s[i+1]!= ')') invalidRight++;
                else {i++;} 
                
                if(stack == 0) invalidRight++;
                else stack--;
            }
        }
        return invalidRight + 2*stack;
    }
};