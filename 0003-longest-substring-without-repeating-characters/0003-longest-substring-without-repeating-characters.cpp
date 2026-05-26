class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        int i=0;
        int j=0;
        int mws=0;
        unordered_set<int>st;

        while(j<n)
        {

            if(st.find(s[j])!=st.end())
            {
                st.erase(s[i]);
                i++;
            }
            else
            {
                st.insert(s[j]);
                mws=max(mws,j-i+1);
                j++;
            }
         
        }
        return mws;
    }
};