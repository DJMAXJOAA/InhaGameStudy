//Counting Bits

class Solution {
public:
    vector<int> countBits(int n) {
        int cnt = 0;
        vector<int> ansArr;

        for (int i = 0; i <= n; i++)
        {
            cnt = 0;
            int temp = i;
            //2������ ���� �� 1�� ����� üũ
            while (temp)
            {
                if (temp % 2 == 1) cnt++;
                temp /= 2;
            }

            ansArr.push_back(cnt);
        }

        return ansArr;
    }
};