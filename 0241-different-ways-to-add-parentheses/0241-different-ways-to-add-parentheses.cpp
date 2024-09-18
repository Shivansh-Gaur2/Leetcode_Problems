class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        if(expression.find_first_of("+-*") == string::npos){
            ans.push_back(stoi(expression));
            return ans;
        }

        for(int i = 0 ; i < expression.size() ;i++){
            char ch = expression[i];

            if(ch == '*' || ch == '+' || ch == '-'){
                vector<int>leftArr = diffWaysToCompute(expression.substr(0, i));
                vector<int>rightArr = diffWaysToCompute(expression.substr(i+1));

                for(auto left : leftArr){
                    for(auto right : rightArr){
                        if(ch == '*'){
                            ans.push_back(left * right);
                        }
                        else if(ch == '-'){
                            ans.push_back(left - right);
                        }
                        else{
                            ans.push_back(left + right);
                        }
                    }
                }


            }
        }
        return ans;
    }
};