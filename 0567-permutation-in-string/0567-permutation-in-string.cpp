class Solution {
public:
bool checkInclusion(string s1, string s2) 
{
    int n1 = s1.size();
    int n2 = s2.size();

    if(n1 > n2) return false;

    vector<int> v1(26, 0); // s1 ke character frequency store karega
    vector<int> v2(26, 0); // s2 ke window ke character frequency store karega

    // Pehle s1 ke characters ki frequency ko count karo
    for(auto it: s1)
    {
        v1[it - 'a']++;
    }

    int i = 0, j = 0;

    // Sliding window approach lagao
    while(j < n2)
    {
        // Window me current character ko add karo
        v2[s2[j] - 'a']++;

        // Agar window size n1 ke barabar ho jaaye
        if(j - i + 1 == n1)
        {
            // Compare karo ki dono vectors same hain ki nahi
            if(v1 == v2) return true;
        }

        // Agar window size n1 se chhoti hai, to bas window ko badhao
        if(j - i + 1 < n1)
        {
            j++;
        }
        else
        {
            // Agar window size n1 ke barabar ho gai hai, aur chracter abhi mila bhi nhi hai ,to piche wale character ko nikalo
            v2[s2[i] - 'a']--;
            i++;
            j++;
        }
    }

    return false;
}

};