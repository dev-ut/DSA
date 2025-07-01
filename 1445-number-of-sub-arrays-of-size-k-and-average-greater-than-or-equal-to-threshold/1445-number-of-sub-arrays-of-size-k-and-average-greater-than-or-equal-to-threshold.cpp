class Solution {
public:
int numOfSubarrays(vector<int>& arr, int k, int threshold) 
{
    int n = arr.size();  // array ka size nikal rahe hain
    
    int i = 1;           // i ko window ke starting index ke liye rakha hai
    int j = k;           // j ko window ke ending index ke liye rakha hai
    int prevwindosum = 0; // pehli window ka sum store karne ke liye
    int currentwindowsum = 0; // current window ka sum, yeh update hoga
    int count = 0;       // threshold se zyada subarrays ka count store karne ke liye

    // Pehli window ka sum calculate karo (pehle k elements ka sum)
    for (int it = 0; it < k; it++) {
        prevwindosum += arr[it];  // pehli window ka sum
    }
    
    // Pehli window ka average check karo, agar threshold se zyada hai to count badhao
    if (prevwindosum / k >= threshold) 
    {
        count++;  // agar pehli window ka sum threshold ke barabar ya zyada hai to count++
    }

    // Ab sliding window ka logic lagao
    while (j < n) {
        // Naye element ko window me add karo aur pehle element ko subtract karo
        currentwindowsum = prevwindosum - arr[i - 1] + arr[j];

        // Current window ka average check karo
        if (currentwindowsum / k >= threshold) {
            count++;  // agar current window ka sum threshold se zyada ya barabar hai to count++
        }

        // Previous window sum ko current window sum se update karo
        prevwindosum = currentwindowsum;

        // Window ke pointers ko aage badhao
        i++;
        j++;
    }

    return count;  // Total count return karo jisme threshold se zyada window sums hain
}

};