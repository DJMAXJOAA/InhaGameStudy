class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = a ^ b;
        unsigned int carry = (a & b);
        carry = carry<<1;
        
        while(carry)
        {
            int newSum = sum ^ carry;
            unsigned int newCarry = (sum & carry);
            
            newCarry = newCarry<<1;
            
            sum = newSum;
            carry = newCarry;
        }

        return sum;
    }
};