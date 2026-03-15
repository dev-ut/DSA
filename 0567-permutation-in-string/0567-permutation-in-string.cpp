class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
      int n1=s1.length();
      int n2=s2.length();
      // first length check only 
      if(n1>n2) return false;

      vector<int>v1(26,0);
      vector<int>v2(26,0);

      // filling up the v and making the respective places for s1 string 
      for(int i=0;i<n1;i++)
      {
        v1[s1[i]-'a']++;    // just updating it to 1 from 0
      }
      // now iterate over string s2 and check the following conditions 
      int i=0;
      int j=0;
      while(j<n2)
      {
        // just mark the places 
        v2[s2[j]-'a']++;

        // if window completly mil gai equal to length of string 1
        if(n1==(j-i+1))
        {
            if(v1==v2) return true;
        }
        // agr choti hai 
        if((j-i+1)<n1)
        {
            j++;    // simply
        }
        else        // agr barbar ho gai hai par character are not matching shrink the window 
        {
         v2[s2[i]-'a']--;
         i++;
         j++;
        }

      }
      return false ;// otherwise     
    }
};