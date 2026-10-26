class Solution {
public:
    string reverseVowels(string s) 
    {
      
    int i = 0;
    int j = s.length() - 1;

    while(i < j)
    {
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' ||
           tolower(s[i]) == 'i' || tolower(s[i]) == 'o' ||
           tolower(s[i]) == 'u')
        {
            while(i < j &&
                  !(tolower(s[j]) == 'a' || tolower(s[j]) == 'e' ||
                    tolower(s[j]) == 'i' || tolower(s[j]) == 'o' ||
                    tolower(s[j]) == 'u'))
            {
                j--;
            }

            if(i < j)
            {
                swap(s[i], s[j]);
                j--;
            }
        }
        i++;
    }

    return s;
}
};