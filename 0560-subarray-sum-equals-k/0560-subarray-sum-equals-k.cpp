class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        // this slinding window approch is not valid if negative lemnts are presnt as ki hmen smjh nhi ayega ki kab window bdhana hai kab ghatna hai  
    //    int n=nums.size();
    //    int sum=0;
    //    int i=0;
    //    int j=0;
    //    int count=0;
    //    while (j < n) 
    // {
    //     sum += nums[j];

    //     while (sum > k && i <= j)   // shrink window jab sum bada ho
    //     {
    //         sum -= nums[i];
    //         i++;
    //     }

    //     if (sum == k)   // agar window ka sum k ke barabar hai
    //     {
    //         count++;
    //     }

    //     j++;
    // }

    // return count;

    //isliye we are hgoing to use hasmpa + prefix sum approch 
        int n= nums.size();
        // create prefix array in palce
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        // create and loop up and aad the frequency if found
         for(int i=0;i<n;i++)
        {
            cout<<nums[i]<<",";
        }
        unordered_map<int,int> map;

        int count=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==k)count++;   // if dierct k== index value 
            int rem=nums[i]-k;    
            if(map.find(rem)!=map.end()) count=count+map[rem];
            
            map[nums[i]]++;
        }
        return count;
    }
};