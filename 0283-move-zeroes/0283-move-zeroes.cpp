class Solution {
public:
void moveZeroes(vector<int>& nums)
{
    int n = nums.size();
    int i = 0; // slow pointer: next position to place non-zero

    // Step 1: Move all non-zero elements to front
    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    // Step 2: Fill remaining positions with 0
    while (i < n)
    {
        nums[i] = 0;
        i++;
    }
}

};