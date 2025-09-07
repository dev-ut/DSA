class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n=fruits.size();
        int i=0;
        int j=0;
        int maxfruits=-1;
        unordered_map<int,int>mp;

        while(j<n)
        {
           mp[fruits[j]]++;
           
           while(mp.size()>2)  // coz there are two baskets 
           {
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0)
            {
                mp.erase(fruits[i]);
            }
            i++;

           }
           maxfruits=max(maxfruits,j-i+1);
           j++;
        }
        return maxfruits;

    }
};