class Solution {
public:
int characterReplacement(string s, int k) 
{
    int maxlength = 0;   // track karega max valid window ka size
    map<char, int> mp;   // yeh map har character ki frequency ko store karega
    int maxfreq = 0;     // window me jo sabse zyada frequent character hai uska count track karega
    int i = 0;           // sliding window ka left pointer

    // Outer loop - right pointer ko window expand karte jao
    for(int j = 0; j < s.length(); j++)
    {
        mp[s[j]]++;   // current character ko map me add karo
        maxfreq = max(maxfreq, mp[s[j]]);   // maxfreq ko update karo window ke andar ka

        // Check karo ki required replacements allowed hai ya nahi
        while((j - i + 1) - maxfreq > k)    // agar conversions (window size - maxfreq) zyada ho rahi hain
        {
            mp[s[i]]--;   // left pointer ko slide karo aur character ko map se ghatao
            i++;          // left pointer ko ek step aage badhao
        }

        maxlength = max(maxlength, j - i + 1);   // max valid window ka size update karo
    }

    return maxlength;   // final max length return karo
}

    
};