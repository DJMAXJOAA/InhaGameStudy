class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0; // ������� ���� ������ �ִ� �ε���

        for (int i = 0; i < nums.size(); ++i) {
            // ���� ��ġ������ �ִ� ���� �Ÿ��� ����
            maxReach = max(maxReach, i + nums[i]);

            // ���� ���� ��ġ�� �ִ� ���� ���� �ε����� �Ѿ�� ������ �� ����
            if (maxReach <= i && i < nums.size() - 1) {
                return false;
            }
        }

        return true; // ������ �ε������� ���� ����
    }
};