class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        if (s.length() == 0) {
            return result;
        }
        result += s.length();

        for (int i = 0; i < s.length(); i++) {
            //i is the length of substring
            for (int j = i + 1; j < s.length(); j++) {
                int start = i;
                int end = j;
                bool flag = true;

                if (s[start] == s[end]) {
                    while (start < end) {

                        if (s[start] != s[end]) {
                            flag = false;
                            break;
                        }
                        start++;
                        end--;
                    }

                    if (flag == true) {
                        cout << i << " " << j << "\n";
                        result++;
                    }
                }
            }
        }
        return result;
    }
};