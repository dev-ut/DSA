class Solution {
public:
vector<int> twoSum(vector<int>& numbers, int target) 
{
    int lo = 0;  // Start from index 0
    int hi = numbers.size() - 1;  // Last valid index

    while (lo < hi) 
    {
        int sum = numbers[lo] + numbers[hi];
        if (sum == target) 
        {
            return {lo + 1, hi + 1}; // 1-indexed output as required
        } 
        else if (sum < target) 
        {
            lo++; // Need a bigger sum
        } 
        else 
        {
            hi--; // Need a smaller sum
        }
    }

    return {}; // No valid pair found
}
};