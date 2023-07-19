class Solution {
public:
    int getSum(int a, int b)
    {

        if (a == -b) return 0;

        while (a != 0)
        {
            unsigned int carry = (a & b);
            b = a ^ b;
            a = carry << 1;
        }

        int ans = a | b;

        return ans;
    }
};