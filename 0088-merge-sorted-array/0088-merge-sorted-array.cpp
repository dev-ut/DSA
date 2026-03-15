class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // eak ddora vector bayen and just expolre the meachnisams 
          vector<int>ans(m+n);

          int i=0;
          int j=0;
          int k=0 ; // just for the3rd vector 

          while(i<m && j<n)
          {
            if(nums1[i]<=nums2[j])
            {
                ans[k++]=nums1[i++];
            }
            else
            {
                ans[k++]=nums2[j++];
            }
          }
          // agr nums1 bdi hai 
          while(i<m)
          {
            ans[k++]=nums1[i++];
          }

          // agr nums2 me elments bach gaye hain 
          while(j<n)
          {
            ans[k++]=nums2[j++];
          }

          // ab ans ko sare elmnets nums1 me daal do or just return ans 
          for(int i=0;i<ans.size();i++)
          {
            nums1[i]= ans[i];
          }




    }
};