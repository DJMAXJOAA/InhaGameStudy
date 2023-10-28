class Solution {
public:
    bool isValid(string s) {
        
        stack<char> answer;

        for(int i = 0; i <s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
                answer.push(s[i]);
            else if(!answer.empty())
            {
                char temp = answer.top();

                if(temp == '(' && s[i] != ')')
                    return false;
                else if(temp == '{' && s[i] != '}')
                    return false;
                else if(temp == '[' && s[i] != ']')
                    return false;
                
                answer.pop();
            }
            else
                return false;
        }

        if(!answer.empty())
            return false;

        return true;
    }
};
