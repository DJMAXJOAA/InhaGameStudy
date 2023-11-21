class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0; // 현재까지 도달 가능한 최대 인덱스

        for (int i = 0; i < nums.size(); ++i) {
            // 현재 위치에서의 최대 점프 거리를 갱신
            maxReach = max(maxReach, i + nums[i]);

            // 만약 현재 위치가 최대 도달 가능 인덱스를 넘어가면 도달할 수 없음
            if (maxReach <= i && i < nums.size() - 1) {
                return false;
            }
        }

        return true; // 마지막 인덱스까지 도달 가능
    }
};