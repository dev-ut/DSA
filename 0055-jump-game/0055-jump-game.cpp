class Solution {
public:
bool canJump(vector<int>& nums) 
{
    // greedy soln

    int maxitcango = 0;  // ab maxitcango ko maxgone bolenge
    int maxgone = 0;     // aur maxgone ko maxitcango banayenge

    for (int i = 0; i < nums.size(); i++) 
    {
        if (i > maxgone) return false;  // agar current index tak nahi pahuch paaye

        maxitcango = i + nums[i];  // ab tak jitna aage jaa sakte hain

        maxgone = max(maxitcango, maxgone);  // maximum distance update karo

        if (maxgone >= nums.size() - 1) return true;  // agar last index tak pahuch gaye ho
    }

    return true;  // agar loop khatam ho gaya aur last tak pahuch gaye
}


};