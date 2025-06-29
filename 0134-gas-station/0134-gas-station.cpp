class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int totalGas = 0, totalCost = 0, currentGas = 0, start = 0;
        int n = gas.size();
        
        for (int i = 0; i < n; ++i) 
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            // If currentGas is negative, reset the starting point
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }
        
        // If total gas is less than total cost, return -1
        if (totalGas < totalCost) 
        {
            return -1;
        }
        
        return start;

    }
};