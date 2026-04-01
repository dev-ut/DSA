class Solution {
public:
int solve(int n,vector<int>&memo)
{
    if(n==0 ||n==1) return 1;

    if(memo[n]!=-1) return memo[n];
    
    int onestepdown=solve(n-1,memo);
    int twostepdown=solve(n-2,memo);

    return memo[n]=onestepdown+twostepdown;
}
    int climbStairs(int n) 
    {
        // top down dp 
        vector<int>memo(n+1,-1);
        return solve(n,memo);
    }
};