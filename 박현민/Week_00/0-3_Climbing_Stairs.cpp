class Solution {
public:
    int climbStairs(int n) {
        int x = 1;
        int y = 0;

        while (n > 1)
        {
            int temp = x;
            x += y;
            y = temp;
            n--;
        }

        return x + y;
    }
};