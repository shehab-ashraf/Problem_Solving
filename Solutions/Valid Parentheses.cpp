class Solution {
public:
    bool isValid(string A) {
        stack<char> S;
        string OpeningParentheses  = "{([";
        map<char,char> ClosingParentheses { {'}','{'} , {')','('} , {']','['} };
        for(int i = 0 ; i < A.length() ; i++) {
            size_t found = OpeningParentheses.find(A[i]);
            if (found != string::npos) S.push(A[i]);
            else if(!S.empty() && S.top() ==  ClosingParentheses[A[i]])
                S.pop();
            else return 0;
        }
        return S.empty();
    }
};
