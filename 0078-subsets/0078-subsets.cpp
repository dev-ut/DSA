class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>& fans,vector<int>&ans,int n,int indx)
{
     // basce cae
     if(indx==n)
     {
        fans.push_back(ans);
        return ;
     }
    //take
    ans.push_back(nums[indx]);
    solve(nums,fans,ans,n,indx+1);

    // notake case
    ans.pop_back();
    solve(nums,fans,ans,n,indx+1);

}

    vector<vector<int>> subsets(vector<int>& nums) 
    {
     int n=nums.size();
     vector<vector<int>>fans;
     vector<int>ans;
     solve(nums,fans,ans,n,0);   
     return fans;
    }
};