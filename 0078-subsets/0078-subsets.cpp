class Solution {
public:
vector<vector<int>> solve(vector<int>& nums, int i, vector<int> ans,vector<vector<int>>&fans)
{
    if(i>=nums.size())
    {
        fans.push_back(ans);
        return fans;
    }
    // take and notake
  // Take the current element
    ans.push_back(nums[i]);
    solve(nums, i + 1, ans, fans);
    // notake
    ans.pop_back();
    solve(nums, i + 1, ans, fans);

    return fans;
}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> ans;
        vector<vector<int>>fans;
        return solve(nums,0,ans,fans);
    }
};