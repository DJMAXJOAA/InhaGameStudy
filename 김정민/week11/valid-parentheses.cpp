class Solution {
public:
    bool isValid(string s) {
        stack<char> S;

        for(int i=0; i<s.size(); i++) {
            char cur = s[i];
            
            if(S.empty()) {
                if(cur == ')' || cur == '}' || cur == ']') return false;
                S.push(cur);
                continue;
            }

            if(cur == '(' || cur == '{' || cur == '[') {
                S.push(cur);
                continue;
            }

            char top = S.top();
            if(cur == ')') {
                if(top != '(') return false;
            }
            else if(cur == '}') {
                if(top != '{') return false;
            }
            else if(cur == ']') {
                if(top != '[') return false;
            }
            S.pop();
        }

        if(S.empty()) return true;
        else return false;
    }
};