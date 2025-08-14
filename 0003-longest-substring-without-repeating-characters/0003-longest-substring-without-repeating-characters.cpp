class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        int i=0;
        int j=0;
        int mxlgth=0;
        unordered_set<char>st;

        while(j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                mxlgth=max(mxlgth,j-i+1);
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return mxlgth;
    }
};