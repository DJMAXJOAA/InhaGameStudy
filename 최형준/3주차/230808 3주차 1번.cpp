//Time taken: 1 hr 33 m 32 s
//Runtime
//122ms
//Beats 47.06 % of users with C++
//Memory
//15.52mb
//Beats 50.65 % of users with C++

class Solution {
public:
    void coinCal(vector<int>& coins, int curAmount, int count, vector<int>& save)
    {
        if (curAmount < 0)
            return;

        if (curAmount == 0)
        {
            save[0] = min(save[0], count);
            return;
        }

        if (count < save[curAmount])
        {
            for (int i = 0; i < coins.size(); i++)
            {
                save[curAmount] = count;
                coinCal(coins, curAmount - coins[i], count + 1, save);
            }
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        vector<int> save(amount + 1, INT_MAX);

        sort(coins.begin(), coins.end(), greater<int>());

        coinCal(coins, amount, 0, save);
        if (save[0] == INT_MAX)
            return -1;
        return save[0];
    }
};