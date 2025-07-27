class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
 int n=s.length();    // String s ka length n me rakh lein
int i=0;             // i starting index ko represent kare hai (window ka left boundary)
int j=0;             // j ending index ka representation hai (window ka right boundary)
int count=0;         // count variable initialize kiya gya hai jo current substring ki length ko track kare hai
int maxcount=0;      // maxcount maximum substring ki length rakhai jo ab tak mili hai
unordered_set<char>st;  // unordered_set ka use ho rha hai jisme unique characters ko rakhai jata hai jo window me hai

while(j<n)  // jab tak right boundary string ke length ke andar hai tab tak loop chalai jayi
{
  
    if(st.find(s[j])==st.end())  // agar current character (s[j]) set ke andar nahi hai
    {
        st.insert(s[j]);         // to us character ko set me daal diye
        maxcount=max(maxcount,j-i+1);  // maximum length ko update kar diye agar current window ka size bada hai
        j++;                     // ab window ka right boundary (j) ek position aage badha diye
    }
    else  // agar current character set me pahile se hai, matlab wo repeat ho rha hai
    {
        st.erase(s[i]);    // set se starting character hata diye (window ka left end)
        i++;               // aur window ka left boundary ek position aage badha diye  mil jaye to  shringk the window
    }
}
return maxcount;  // maximum length wali substring ka size return kare hai

    }
};