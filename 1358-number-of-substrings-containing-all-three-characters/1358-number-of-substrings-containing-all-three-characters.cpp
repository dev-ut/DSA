class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int size=s.length();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<int,int>mp;
        while(j<size)
        {
            mp[s[j]]++;  // just increase the count;

            while(mp.size()==3) // atleast 3 charcaters
            {
             count+=size-j;   // why (size - j) is. suppose carry a case aaaabcabc  
             mp[s[i]]--;  // deleting from map the exat i chracter
             if(mp[s[i]]==0)
             {
                mp.erase(s[i]);
             }
            
             i++;
            }
            
            j++;
        }
         return count;
    }
};

// why (size - j) is. suppose carry a case aaaabcabc  so hmen if we do j-i+1 to it will count no of a also but abc window should only consitute abc no matter how many a b or c are present is achived by n-j;