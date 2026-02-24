class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n =fruits.size();
        int i=0;
        int j=0;
        int mxlength=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
         mp[fruits[j]]++;
         if(mp.size()>2)
         {
           while(mp.size()>2 && i<=j)
           {
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0)
            {
                mp.erase(fruits[i]);
            }
            i++; // shrinking the window
           }
         }
         mxlength=max(mxlength,j-i+1);

         j++;
        }
        return mxlength;
    }
};