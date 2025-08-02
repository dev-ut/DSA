class Solution {
public:
    bool isPalindrome(string s) 
    {
       int n=s.length();
       string str="";

       // removing all the special characters including space 

       for(int i=0;i<n;i++)
       {
        if(isalnum(s[i]))
        {
          str+=tolower(s[i]);   // yhn se khali string taiyr ho gyi plane eakdum
        }
       }

       cout<<str;
      int i=0;
      int j=str.length()-1;
      while(i<=j)
      {
          if(str[i]!=str[j]) return false;
          i++;
          j--;
      } 

      return true;
    }
};