class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Cleaning the array
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Marking the presence
        for (int i = 0; i < n; i++) {
            int no = abs(nums[i]);

            if (no > n)
                continue;

            nums[no - 1] = -abs(nums[no - 1]);
        }

        // Scan for first positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};