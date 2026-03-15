class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n =fruits.size();
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int mxlength=0;
        while(j<n)
        {
            mp[fruits[j]]++;
            // agr elmnts in basket Ie: map main agr exceed krte hain to just shrink the window
            if(mp.size()>2)
            {
                while(mp.size()>2 && i<=j)
                {
                    mp[fruits[i]]--;
                   if(mp[fruits[i]]==0)
                   {
                     mp.erase(fruits[i]);
                   }
                   i++; 
                }
            }
            mxlength=max(mxlength,j-i+1);
           j++;
        }
        return mxlength;
    }
};
// note : we just have to give the count s see the 3 example we are just returning the window 2 basket can hold . and try to act map like a basket.