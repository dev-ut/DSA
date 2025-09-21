class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ans, vector<vector<int>>& fans, int indx, int target, int n) {
        if (target == 0) {
            fans.push_back(ans);
            return;
        }
        if (target < 0 || indx == n) return;

        // TAKE
        ans.push_back(nums[indx]);
        solve(nums, ans, fans, indx + 1, target - nums[indx], n); // ek baar hi le sakte hain Combination Sum II me
        ans.pop_back();

        // NOT TAKE (skip duplicates)
        while (indx + 1 < n && nums[indx] == nums[indx + 1]) {  // why indx+1 // so that out of bounds na jaye
            indx++;
        }
        solve(nums, ans, fans, indx + 1, target, n);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // duplicates handle karne ke liye
        int n = nums.size();
        vector<vector<int>> fans;
        vector<int> ans;
        solve(nums, ans, fans, 0, target, n);
        return fans;
    }
};
