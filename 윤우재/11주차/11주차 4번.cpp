class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(char c : s)
        {
            if(stack.empty())
            {
                stack.push_back(c);
                continue;
            }
            switch(c)
            {
                case ')':
                    if(stack.back() == '(')
                        stack.pop_back();
                    else
                        stack.push_back(c);
                break;
                
                case '}':
                    if(stack.back() == '{')
                        stack.pop_back();
                    else
                        stack.push_back(c);
                break;
                case ']':
                    if(stack.back() == '[')
                        stack.pop_back();
                    else
                        stack.push_back(c);
                break;
                default:
                    stack.push_back(c);
                    break;
            }
        }
        return stack.empty();
    }

};