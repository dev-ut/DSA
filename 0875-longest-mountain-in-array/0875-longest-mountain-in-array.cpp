class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n = arr.size();
        if(n < 3) return 0;

        int maxlen = 0;

        for(int pkindx = 1; pkindx < n - 1; pkindx++)
        {
            // peak hona chahiye: left aur right dono se bada
            if(arr[pkindx] > arr[pkindx - 1] && arr[pkindx] > arr[pkindx + 1])
            {
                int i = pkindx - 1;
                int j = pkindx + 1;

                // left side wale strictly increasing check
                while(i > 0 && arr[i] > arr[i - 1])
                {
                    i--;
                }

                // right side wale strictly decreasing check
                while(j < n - 1 && arr[j] > arr[j + 1])
                {
                    j++;
                }

                // length nikal lo mountain ka
                int currlen = (j - i + 1);
                maxlen = max(maxlen, currlen);

                // already j tak check ho chuka, toh pkindx ko j tak le jao
                pkindx = j;
            }
        }

        return maxlen;
    }
};
