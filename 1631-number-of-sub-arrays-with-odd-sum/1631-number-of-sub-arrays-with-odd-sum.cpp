class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        // cocpet 
    int odd = 0, even = 1; // prefix sum 0 is even cosidering that case
    int sum = 0, count = 0, MOD = 1e9+7;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum % 2 == 0) {
            count = (count + odd) % MOD;
            even++;
        } else {
            count = (count + even) % MOD;
            odd++;
        }
    }

    return count;
}

};