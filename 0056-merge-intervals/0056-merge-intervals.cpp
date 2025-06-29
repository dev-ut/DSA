class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> ans;
    if (intervals.size() == 0) return ans; // Agar intervals empty hain, to directly return kar do empty ans.

    sort(intervals.begin(), intervals.end()); // Pehle intervals ko sort kar do start time ke hisaab se.

    int st = intervals[0][0]; // Start ko initialize karo pehle interval ke start se.
    int end = intervals[0][1]; // End ko initialize karo pehle interval ke end se.

   for (int i = 1; i < intervals.size(); i++) // Ek-ek karke baaki intervals check karo.
   {
     if (end >= intervals[i][0]) // starting point of i2 ke
     { 
        // to iska matlab overlap ho raha hai. End ko badha do.
        end = max(end, intervals[i][1]); 
     } 
     else 
     {
        // Agar overlap nahi ho raha, to current interval ko answer mein add karo.
        ans.push_back({st, end}); // Purane start aur end ko result mein add karo.
        st = intervals[i][0]; // Naya start ab current interval ka start hoga.
        end = intervals[i][1]; // Naya end ab current interval ka end hoga.
     }
   }
  ans.push_back({st, end}); // Last interval ko bhi result mein add karna mat bhoolo.
  return ans; // Merged intervals return karo.
}
};