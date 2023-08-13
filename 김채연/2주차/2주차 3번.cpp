// Q3. Best Time to Buy and Sell Stock
// 
// �׸��� ������ ����,
// O(N^2) Ǯ�̷δ� �Է°��� �ִ� ũ�Ⱑ 10^5�̹Ƿ� �Ұ���. -> ??
// ���� �׸��� ������� ����, (�׸��� ���: �� ���� ���� ���� ���̴� �͸� �����ϰ� ���߿� ��ĥ ������ ������� �ʴ�)
// �ּҰ��� �����ذ��� ���ÿ� �ִ� ������ �����ϴ� ���� ����Ʈ.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 2147000000, answer = 0;
        //�ּҰ��� �����ذ��� ���ÿ� �ִ� ������ �����Ѵ�.
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            answer = max(answer, prices[i] - minPrice);
        }

        return answer;
    }
};