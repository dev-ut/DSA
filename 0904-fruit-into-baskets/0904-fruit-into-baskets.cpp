class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        // here map will act as a conatainer of size 2
        int n=fruits.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int mx=INT_MIN;
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
                     i++;
                }
            }

            mx=max(mx,j-i+1);
            j++;

        }
        return mx;

    }
};