[10���� 2��] / Longest Consecutive Sequence / 1�ð� / https://leetcode.com/problems/longest-consecutive-sequence/

[���� ����]
��� �˰��� = �ؽ� ���̺� (unordered_set) :: O(n)
1. nums �迭�� �ؽ����̺� ����
2. ���ӵǴ� �迭�� ������ ã�� (���� ���Ұ����� 1 ���� ���� �ִ���? -> ������ �������� �� �� ����)
3. ���ӵǴ� ���ڸ� while �� �ȿ��� ã�� (���� ������ �ʼ� �κ��� �ƴ�)

[�߰� ����]
1. �ؽ� ���̺��� ������ ���� ���� ���·� ���Եȴ� (�ݺ��ڸ� ����ϴ� ���� �ǹ̰� ����)
2. ���� �ӵ��� O(1) ~ �־��� ��Ȳ���� O(n)����, ���ҿ� ������ ������ ������ �� ����

[������]
1. ������ �̸� ū �迭�� �������� �����鼭(�迭 ��뿡 ���� O), Ư�� ���ҿ� ������ �����ؾ� �ϴ� ��� unordered_set
2. ������ �Ǿ� �ϴ� ��쿡�� �Ϲ� set ����ϱ�

[�ٸ� Ǯ�� ���]
1. ���� :: O(n log n)

Time taken : 59 m 27 s
Runtime 129ms
Beats 57.48 % of users with C++
Memory 70.79MB
Beats 9.65 % of users with C++

// [9,1,4,7,3,-1,0,5,8,-1,6] -> 7

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> save(nums.begin(), nums.end());
        int result = 1;

        for (int num : nums)
        {
            // ã������ ������ ���ӵǴ� ���� ���� ������ �н�
            // ã������ ���� �������̴� save.count(nums - 1)�� �ٲ㼭 ��� ����, ��ɿ� ũ�� ���� ����
            if (save.find(num - 1) == save.end())
            {
                int findVal = num;
                int current = 1;

                while (save.find(findVal + 1) != save.end())
                {
                    findVal++;
                    current++;
                    // ���� üũ�Ҷ� ������ ����� �� �����
                    save.erase(findVal);
                }

                result = max(result, current);
            }
        }

        return result;
    }
};

[�ٸ� Ǯ�� ���]
����::O(n log n)
1. set�� �ڵ� ������ �̿�����
2. unordered_map�� �޸� �����ؼ� ���ϴ�, �ݺ��� ����� ���� / ������ ���Ŀ� �ð� �ҿ�

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    set<int> num_set(nums.begin(), nums.end());
    int longestStreak = 1;
    int currentStreak = 1;

    for (int num : num_set) {
        // ���� ���ڰ� ���� ������ �����̶�� ��Ʈ���� ������ŵ�ϴ�.
        if (num_set.find(num - 1) != num_set.end()) {
            currentStreak++;
            longestStreak = max(longestStreak, currentStreak);
        }
        else {
            // ������ ����ٸ� ��Ʈ���� �缳���մϴ�.
            currentStreak = 1;
        }
    }
    return longestStreak;
}
