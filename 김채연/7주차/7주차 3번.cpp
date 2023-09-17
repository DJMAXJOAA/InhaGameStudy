// medium 
//index가 1 보다 작은 모든 수의 곱, index가 1 보다 큰 모든 수의 곱 두 가지 값이 필요하다.

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        Arrays.fill(ans, 1);
        int curr = 1;
        for (int i = 0; i < n; i++) { //해당 인덱스보다 앞
            ans[i] *= curr;
            curr *= nums[i];
        }
        curr = 1;
        for (int i = n - 1; i >= 0; i--) { //해당 인덱스보다 뒤
            ans[i] *= curr;
            curr *= nums[i];
        }
        return ans;
    }
}