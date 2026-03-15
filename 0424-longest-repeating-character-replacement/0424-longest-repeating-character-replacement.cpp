class Solution {
public:
    int characterReplacement(string s, int k) 
    {
      int n = s.length();
      int i=0;
      int j=0;
      int mxfreq=0;
      int mxlength=0;
      unordered_map<int,int>mp;
      while(j<n)
      {
        // now we will just add in map and count the maximumfrquency 
        mp[s[j]]++;
        mxfreq=max(mxfreq,mp[s[j]]);

        // now we will just use the formula 
        while((j-i+1)-mxfreq >k) // jb tk k is bda no problem but if chota
        {
         mp[s[i]]--;    // we are just delting the current value and shrinking it
         i++;          // shriking of i ;
        }

        mxlength=max(mxlength,j-i+1);
        j++;
    } 
    return mxlength;
    }
};
// note imp formula : whensoevr we have to make an asuumption ki we hae chnged some value we use (window_size - maxfreq > k) jb tk k bdi rhegi tb tk we assume that we have already changed it .
