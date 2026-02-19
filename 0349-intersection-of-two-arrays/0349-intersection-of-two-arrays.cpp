class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n1; i++) {
            mp[nums1[i]]++;
        }
        // agr wo wlmnts map mai pehle se hi prent hai to ans vectormain store
        // krte rho
        for (int i = 0; i < n2; i++) 
        {
            if (mp.find(nums2[i]) != mp.end()) 
            {
                ans.push_back(nums2[i]);
                while (mp[nums2[i]] > 0) 
                {
                    mp[nums2[i]]--;
                }
                if (mp[nums2[i]] == 0) 
                {
                    mp.erase(nums2[i]);
                }
            }
        }
        return ans;
    }
};