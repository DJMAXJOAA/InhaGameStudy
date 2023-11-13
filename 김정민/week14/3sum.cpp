class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];

            int st = i+1;
            int en = nums.size()-1;

            while(st < en) {
                int sum = num + nums[st] + nums[en];
                
                if(sum == 0) {
                    vector<int> tmp{num, nums[st], nums[en]};
                    ans.push_back(tmp);

                    // 같은 조합 회피를 위해 st, en 이동
                    // cout << nums[st] << ' ' << nums[en] << endl;
                    while(st < en && nums[st] == nums[st+1]) st++;
                    while(st < en && nums[en] == nums[en-1]) en--;

                    st++; en--;

                    continue;
                }

                if(sum > 0) {
                    // en 줄이기
                    en--;
                }
                else {
                    // st 늘리기
                    st++;
                }
            }

            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};