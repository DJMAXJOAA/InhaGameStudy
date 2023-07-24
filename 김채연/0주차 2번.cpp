class Solution {
public:
    int getSum(int a, int b) {

        int Or = a ^ b;
        int And = (a & b) << 1;

        if (Or == 0)
            return And;
        if (And == 0)
            return Or;
        else
            return getSum(Or, And);
    }

};