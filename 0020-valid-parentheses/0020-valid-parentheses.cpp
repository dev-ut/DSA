class Solution {
public:
    bool isValid(string s) 
    {
        int k=s.length();

        stack<char>st;
        int sts=0;

        for(int i=0;i<k;i++)
        {
            sts=st.size();
            
            
             if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
             {
              st.push(s[i]);
             }
               
            else if(s[i]==')' &&st.top()=='(')
            {
                st.pop();
            }
            else if(s[i]=='}' && st.top()=='{')
            {
                st.pop();
            }
            else if(s[i]==']' && st.top()=='[')
            {
                st.pop();
            }

            
        }
        if(st.size()==0) return true;
        else return false;

    }
};