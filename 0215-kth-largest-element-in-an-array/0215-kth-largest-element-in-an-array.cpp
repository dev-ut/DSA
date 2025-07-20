class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n=nums.size();
        // will  amke a priority  queeue her 
        priority_queue<int ,vector<int>,greater<int>>pq;  // this is max heap insemn smallest elemnt pop honge coz 
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);   // yaad rkhna meecchnaisam ye h ki pehle push ho jata hai k size se bada then pop hota hai
            if(pq.size()>k)
            {
                pq.pop();   
            }

        }
        return pq.top();
    }
};