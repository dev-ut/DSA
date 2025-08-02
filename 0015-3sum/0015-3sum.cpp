class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int n = nums.size();

        // Sorting the array
        sort(nums.begin(), nums.end());  // just to use bs way of two pointers in it 

        // Fix one element and find the other two using two pointers
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicates
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) // avoing shuruwati duplicates 
            {
                int left = i + 1;
                int right = n - 1;

                while (left < right) 
                {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0) 
                    {
                        result.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        // Avoid duplicates
                        while (left < right && nums[left] == nums[left - 1]) // jb tk 
                            left++;
                        while (left < right && nums[right] == nums[right + 1])// jb tk
                            right--;
                    } 
                    else if (sum < 0) 
                    {
                        left++; // as it is soretd so as we move furthere the
                                // distance will tends towards postive side
                    } else 
                    {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};