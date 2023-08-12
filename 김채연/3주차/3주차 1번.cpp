// Q1.Coin Change
// DP방식으로 해결해야 한다.
// 
// EX ) 
// DP의 구현은 간단히 아래와 같은 점화식으로 value의 값을 구성하는 동전의 최소 개수 구현할 수 있다.
// dp[value] = min(dp[value], dp[value - coins종류] + 1);

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, 10001); // amount+1 만큼 객체 생성 후 10001로 초기화.
		int len = coins.size();
		dp[0] = 0; //0을 만드는 건 0이니까 점화식을 위해서 아는건 넣어둠.

		for (int value = 1; value <= amount; ++value) //모든 경우의 수를 생각 (dp를 amount 수 만큼 생성했기 때문)
		{
			for (int i = 0; i < len; ++i) // 코인 개수 만큼 돌리기
			{
				if (value - coins[i] >= 0) // value 보다 coin이 작아야 조합해서 amount 만들기 가능.
					dp[value] = min(dp[value], dp[value - coins[i]] + 1);
				//dp의 value번째 배열에 value를 만드는 최소의 숫자를 넣어준다.
			}

			if (dp[amount] == 10001) // dp배열이 아무 값도 바뀌지 않았다는 뜻 -> amount보다 작은 coin이 없다.
				return -1;

			return dp[amount];
		}

	}
};
