class Solution {
public:
    string reverseWords(string s) 
    {
       int n=s.length();
       vector<string>v;
       int it=0;
       while(it<n && s[it]== ' ')it++; 
       s=s.substr(it); // eak substring bna liya 
       n=s.length();

       string word="";
       for(int i=0;i<n;i++)
       {
         
          if(s[i]==' ')
          {
            if(word!="")
            {
             v.push_back(word);
             word="";
            }
            
          }
          else
          {
              word+=s[i];
          }
         
       }
       // Last word agar bacha ho toh
        if (word != "") 
        {
            v.push_back(word);
        } 

         word=""; // reset it to empty again to use 

       // reverse kr do vector ko 
       for(int i=v.size()-1;i>=0;i--)
       {
        if(i>0)
        {
            word+=v[i];    // tb tk sapce bhi to lagega
            word+=" ";
        }
        else
        {
            word+=v[i];
        }
       }
       return word;
    }
};