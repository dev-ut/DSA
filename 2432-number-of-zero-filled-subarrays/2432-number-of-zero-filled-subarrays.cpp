class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                long long seq = 0;
                // streak of zeros count karo
                while(i < n && nums[i] == 0) {
                    seq++;
                    i++;
                }
                // streak se subarrays add karo
                ans += (seq * (seq + 1)) / 2;
            }
        }
        return ans;
    }
};
