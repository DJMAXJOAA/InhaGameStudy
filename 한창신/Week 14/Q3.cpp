#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        int prev = 1;
        int current = 1;

        for (int i = 1; i < n; i++) {
            int num = s[i] - '0';
            int num2 = (s[i - 1] - '0') * 10 + num;

            int temp = current;

            if (num == 0) {
                if (num2 != 10 && num2 != 20) {
                    return 0;
                } else {
                    current = prev;
                }
            } else if (num2 >= 10 && num2 <= 26) {
                current = current + prev;
            }

            prev = temp;
        }

        return current;
    }
};
