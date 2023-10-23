class Solution {
public:

    bool isPalindrome(string s) {
        string cleanS;
        string reverseS;

        s.erase(remove(s.begin(), s.end(), ' '), s.end());//                    공백 지우기.

        s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end()); //       구두점 지우기.



        for (int i = 0; i < s.size(); i++)//                                    소문자로 통일.
        {
            if ('A' <= s[i] && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }

        cleanS = s;

        reverse(s.begin(), s.end());

        if (cleanS == s)
        {
            cout << "true" << endl;

            return true;
        }
        else
        {
            cout << "false" << endl;

            return false;
        }

    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        bool answer = true;
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (!isalpha(s[left]) && !isdigit(s[left])) {
                left++;
                continue;
            }
            if (!isalpha(s[right]) && !isdigit(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left++]) != tolower(s[right--])) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};