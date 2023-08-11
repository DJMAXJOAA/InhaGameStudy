// Q3. Best Time to Buy and Sell Stock
// 
// 그리디 유형의 문제,
// O(N^2) 풀이로는 입력값의 최대 크기가 10^5이므로 불가능. -> ??
// 따라서 그리디 방식으로 접근, (그리디 방식: 매 순간 가장 좋아 보이는 것만 선택하고 나중에 미칠 영향은 고려하지 않는)
// 최소값을 갱신해가며 동시에 최대 이익을 갱신하는 것이 포인트.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 2147000000, answer = 0;
        //최소값을 갱신해가면 동시에 최대 이익을 갱신한다.
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            answer = max(answer, prices[i] - minPrice);
        }

        return answer;
    }
};