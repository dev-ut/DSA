class Solution {
public:
    void combination(vector<vector<int>>& fans, vector<int>& ans, vector<int>& ar, int target, int idx) 
    {
        // base case
        if (target == 0) 
        {
            fans.push_back(ans);
            return;
        }
        if (target < 0 || idx >= ar.size()) return;

        // TAKE
        ans.push_back(ar[idx]);
        combination(fans, ans, ar, target - ar[idx], idx); // same idx because unlimited use allowed
        ans.pop_back();

        // NOT TAKE
        combination(fans,ans , ar, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& ar, int target) {
        vector<vector<int>>fans;
        vector<int> ans;
        combination(fans, ans, ar, target, 0);
        return fans;
    }
};
