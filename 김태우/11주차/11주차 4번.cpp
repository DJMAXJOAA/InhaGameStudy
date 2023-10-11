class Solution {
public:
    bool isValid(string s)
    {
        stack<char> str;

        for (int i = 0; i < s.size(); i++)
        {
            if (str.empty()) str.push(s[i]);
            else
            {
                char temp = str.top();

                switch (temp)
                {
                case '(':
                    if (s[i] == ')') str.pop();
                    else str.push(s[i]);
                    break;
                case '{':
                    if (s[i] == '}') str.pop();
                    else str.push(s[i]);
                    break;
                case '[':
                    if (s[i] == ']') str.pop();
                    else str.push(s[i]);
                    break;
                default:
                    str.push(s[i]);
                    break;
                }
            }
        }

        return str.empty();

    }
};