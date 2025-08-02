class Solution {
public:
    void reverseString(vector<char>& s) 
    {
         int left = 0, right = s.size() - 1;
        
        while (left < right){
            //swap(s[left], s[right]);
            char temp = s[left];
                 s[left] = s[right];
                 s[right] = temp;

            left++;
            right--;
        }
    }
    
};