#include <vector>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        
        // vector<int> arrA, arrB, arrC;

        // while(a > 0)
        // {
        //     arrA.push_back(a % 2);
        //     a /= 2;
        // }
        // while(b > 0)
        // {
        //     arrB.push_back(b % 2);
        //     b /= 2;
        // }

        // if (arrA.size() > arrB.size())
        // {
        //     for (int i = 0; i < arrB.size(); i++)
        //     {
        //         if ((arrA[i] | arrB[i]) == (arrA[i] & arrB[i]))
        //             arrC.push_back((arrA[i] | arrB[i]) << 1);
        //         else
        //             arrC.push_back(arrA[i] | arrB[i]);
        //     }
        //     arrC.push_back(arrA.back());
        // }
        // else
        // {
        //     for (int i = 0; i < arrA.size(); i++)
        //     {
        //         if ((arrA[i] | arrB[i]) == (arrA[i] & arrB[i]))
        //             arrC.push_back((arrA[i] | arrB[i]) << 1);
        //         else
        //             arrC.push_back(arrA[i] | arrB[i]);
        //     }
        //     arrC.push_back(arrB.back());
        // }
       
        // int c = 0;
        // int size = (arrA.size() > arrB.size()) ? arrA.size() : arrB.size();
        // for(int i = 0; i < size; i++)
        // {
        //     c += arrC[i] * pow(2, i);
        // }
        //    return c;

        while(b!=0)
        {
            unsigned int temp = (a & b);
            a = a ^ b;
            b = temp << 1;
        }
        return a;
    }
};
