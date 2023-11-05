[14���� 2��] / 3Sum / 1�ð� 57�� / https://leetcode.com/problems/3sum/description/

[���� ����]
��� �˰��� = �� ������, ���� : O(n^2) + O(n log n), O(n)
1. ���� �ε��� ���� ����ϴ� �迭
2. ���� �ϳ� ����(low) + �� �����ͷ� ������ �����Ͽ� ���� ������ ã��
3. set �迭�� �����ؼ�, �ߺ� �迭 ������ �̸� ����

[�̽� �� ������]
1. vector<int, int> pair �迭�� ���� �ʿ� ����, �ߺ��� ��Ҵ� �����ϰų� ���ý�Ű�� �ð� + ���� ���⵵�� ������ų �� ����

[�ٸ� Ǯ�� ���]
1. �� ������ : O(n^2), O(1)
2. �ؽ� �� : O(n^2), O(n)
3. ���Ʈ ���� : O(n^3), O(1)

Time taken : 42 m 56 s
Runtime 2151ms
Beats 5.01 % of users with C++
Memory 306.18MB
Beats 5.06 % of users with C++

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> resultSet;

        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < nums.size(); i++)
        {
            sortedNums.push_back(make_pair(nums[i], i));
        }
        sort(sortedNums.begin(), sortedNums.end());

        int prePointer, postPointer;
        int lowValue, midValue, highValue;
        int size = sortedNums.size();
        for (int i = 0; i < size; i++)
        {
            prePointer = i + 1;
            postPointer = size - 1;

            lowValue = sortedNums[i].first * -1;

            while (postPointer > prePointer)
            {
                midValue = sortedNums[prePointer].first;
                highValue = sortedNums[postPointer].first;

                int sum = midValue + highValue;
                if (lowValue == sum)
                {
                    vector<int> temp
                    { -lowValue, midValue, highValue };
                    sort(temp.begin(), temp.end());
                    resultSet.insert(temp);
                }

                if (lowValue < sum)
                {
                    postPointer--;
                }
                else
                {
                    prePointer++;
                }
            }
        }

        vector<vector<int>> result;
        for (auto iter : resultSet)
        {
            result.push_back(iter);
        }
        return result;
    }
};


[�ٸ� Ǯ�� ���]
�� ������ : O(n ^ 2), O(1)
1. �Է� �迭�� ���� ����
2. �ߺ� ó���� ���� ������ �ּ� �ǳʶٰ� ���� (set ��� X)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i])
                twoSumII(nums, i, result);
        return result;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            }
            else if (sum > 0) {
                --hi;
            }
            else {
                res.push_back({ nums[i], nums[lo++], nums[hi--] });
                while (lo < hi && nums[lo] == nums[lo - 1])
                    ++lo;
            }
        }
    }
};


�ؽ� �� : O(n ^ 2), O(n)
1. �� ���� ���� �ؽø��� key�� ����
2. �迭�� ��ȸ�ϸ鼭 -nums[i]�� �ؽøʿ��� �˻�
3. �ߺ��� �����ؾ� �ϱ� ������ Ǯ�̰� ��ٷο� + �߰� ���� ���
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end()); // ����
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // �ߺ� �� �ǳʶٱ�
            unordered_map<int, int> hash_map;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) continue; // �ߺ� �� �ǳʶٱ�
                int complement = -nums[i] - nums[j];
                if (hash_map.count(complement)) {
                    result.push_back({ nums[i], nums[j], complement });
                    hash_map.erase(complement); // �ߺ� ���� ������ �����ϱ� ����
                }
                else {
                    hash_map[nums[j]] = j;
                }
            }
        }
        // ������� �ߺ��� ���� ������ ����
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};


���Ʈ ���� : O(n ^ 3), O(1)
1. ��� ������ ���� ������ �˻�
2. Ǯ�̰� ������������ �ſ� ��ȿ����
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // �����Ͽ� �ߺ� ó���� ���� ����
        for (int i = 0; i < nums.size(); ++i) {
            // �ߺ��� �� �ǳʶٱ�
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                // �ߺ��� �� �ǳʶٱ�
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1; k < nums.size(); ++k) {
                    // �ߺ��� �� �ǳʶٱ�
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }
        return result;
    }
};

