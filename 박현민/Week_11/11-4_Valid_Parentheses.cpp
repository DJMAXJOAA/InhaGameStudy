class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                S.push(s[i]);
                continue;
            }
            if (S.empty()) return false;
            if (s[i] == ')' && S.top() != '(') return false;
            if (s[i] == ']' && S.top() != '[') return false;
            if (s[i] == '}' && S.top() != '{') return false;
            S.pop();
        }
        return S.empty();
    }
};