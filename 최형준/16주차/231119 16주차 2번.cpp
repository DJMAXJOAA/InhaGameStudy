[16���� 2��] / Jump Game / https://leetcode.com/problems/jump-game/description/

[���� ����] ���� ���α׷��� O(n^2), O(n)
1. �� �ε����� ���� ��� ���� ���θ� üũ�ϰ�, ������ �ε��� üũ�迭 ���� ��ȯ

[�ٸ� Ǯ�� ���]
1. �׸��� �˰���
2. �� Ʈ��ŷ

Time taken : 16 m 52 s
Runtime 455ms
Beats 15.97 % of users with C++
Memory 49.09MB
Beats 19.29 % of users with C++

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        vector<bool> check(nums.size() + 1);
        if (nums[0] == 0)
            return false;

        check[0] = true;

        int size = nums.size();
        int done;
        for (int i = 0; i < size - 1; i++)
        {
            if (check[i] == false)
                continue;

            if (i + nums[i] >= size)
                return true;

            for (int j = i; j <= i + nums[i]; j++)
            {
                check[j] = true;
            }
        }
        return check[size - 1];
    }
};

�׸��� �˰���
1. ������� ������ �� �ִ� �ִ� �ε����� �����ϸ鼭, ������ �ε��� ���� ���θ� Ȯ��
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // ������� ������ �� �ִ� �ִ� �ε���
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // i�� �ִ� ���� ���� �ε����� �Ѿ�� ���� �Ұ�
            maxReach = max(maxReach, i + nums[i]); // �ִ� ���� ���� �ε��� ������Ʈ
        }
        return maxReach >= nums.size() - 1; // ������ �ε����� ���� �������� Ȯ��
    }
};


�� Ʈ��ŷ
1. �� �ε������� ������ ������ ��� ������ üũ
2. �ſ� ��ȿ����
class Solution {
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) return true; // ������ �ε����� ������ ���

        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true; // ���� ��ġ���� ������ �ε����� ���� ������ ���
            }
        }
        return false; // ���� �Ұ���
    }

public:
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0, nums); // ���� ��ġ���� Ž�� ����
    }
};
