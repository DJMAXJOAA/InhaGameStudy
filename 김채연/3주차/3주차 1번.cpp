// Q1.Coin Change
// DP������� �ذ��ؾ� �Ѵ�.
// 
// EX ) 
// DP�� ������ ������ �Ʒ��� ���� ��ȭ������ value�� ���� �����ϴ� ������ �ּ� ���� ������ �� �ִ�.
// dp[value] = min(dp[value], dp[value - coins����] + 1);

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, 10001); // amount+1 ��ŭ ��ü ���� �� 10001�� �ʱ�ȭ.
		int len = coins.size();
		dp[0] = 0; //0�� ����� �� 0�̴ϱ� ��ȭ���� ���ؼ� �ƴ°� �־��.

		for (int value = 1; value <= amount; ++value) //��� ����� ���� ���� (dp�� amount �� ��ŭ �����߱� ����)
		{
			for (int i = 0; i < len; ++i) // ���� ���� ��ŭ ������
			{
				if (value - coins[i] >= 0) // value ���� coin�� �۾ƾ� �����ؼ� amount ����� ����.
					dp[value] = min(dp[value], dp[value - coins[i]] + 1);
				//dp�� value��° �迭�� value�� ����� �ּ��� ���ڸ� �־��ش�.
			}

			if (dp[amount] == 10001) // dp�迭�� �ƹ� ���� �ٲ��� �ʾҴٴ� �� -> amount���� ���� coin�� ����.
				return -1;

			return dp[amount];
		}

	}
};
