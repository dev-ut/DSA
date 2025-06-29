class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int n = intervals.size(); // Total number of intervals
    vector<vector<int>> ans;  // Resultant vector jo final answer store karega

    // Har interval par iterate karte hain
    for(int i = 0; i < n; i++)
    {
        int st = intervals[i][0];  // Current interval ka start
        int end = intervals[i][1]; // Current interval ka end

        // Agar current interval `newInterval` ke pehle khatam ho jata hai, to directly add kar do
        if(end < newInterval[0])  // mtlb current interval ends before newInterval starts
        {
            ans.push_back(intervals[i]); // current interval ko answer mein daal do
        }
        // Agar current interval `newInterval` ke baad start hota hai, to newInterval ko add karo
        else if(st > newInterval[1])  // mtlb newInterval ke baad ka interval hai
        {
            ans.push_back(newInterval); // pehle newInterval daalo
            newInterval = intervals[i]; // ab current interval ko `newInterval` bana do taaki baaki intervals ko properly add kar sakein
        }
        // Agar current interval aur `newInterval` overlap kar rahe hain, to merge kar do
        else 
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // minimum start lo dono ka
            newInterval[1] = max(newInterval[1], intervals[i][1]); // maximum end lo dono ka
        }
    }
    
    // Loop ke baad agar `newInterval` abhi bhi bacha hai, to usko answer mein add kar do
    ans.push_back(newInterval);

    return ans; // Final merged intervals return karo
}

};