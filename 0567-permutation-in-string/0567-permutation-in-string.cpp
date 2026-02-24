class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n1=s1.length();
        int n2=s2.length();
        if(n1>n2) return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        // fillling v1 
        for(int i=0;i<n1;i++)
        {
            v1[s1[i]-'a']++;
        }

        // now for v2
        int i=0;
        int j=0;
        while(j<n2)
        {
            v2[s2[j]-'a']++;
            if(n1==j-i+1) // window lenhthsame a gyi to check ki v1 v2 barabr hai ki nhi
            {
              if(v1==v2) return true;
            }
            if(j-i+1<n1)
            {
                j++;
            }
            else
            {
                v2[s2[i]-'a']--;
                i++;
                j++;   //taki window size maintain rhe 
            }
        }
        return false;
    }
};