class Solution {
public:
    bool isValid(string s) 
    {
        int k=s.length();

        stack<char>st;
        int sts=0;

        for(int i=0;i<k;i++)
        {
             if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
             {
              st.push(s[i]);
             }
               
            else if(s[i]==')'&& st.size()>0 &&st.top()=='(')
            {
                st.pop();
            }
            else if(s[i]=='}'&& st.size()>0 && st.top()=='{')
            {
                st.pop();
            }
            else if(s[i]==']'&& st.size()>0 && st.top()=='[')
            {
                st.pop();
            }
            else
            {
                return false;
            }

            
        }
        if(st.size()==0) return true;
        else return false;

    }
};