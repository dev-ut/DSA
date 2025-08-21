class Solution {
public:
bool caneat(int speed,vector<int>& piles, int h)
{
   int n=piles.size(); 
   int count=0;                   //30 hoga first piles not complete array
   for(int i=0;i<n;i++)
   {
       if(speed>=piles[i]) count++;   //23>11 count++
       else if(piles[i]%speed==0) count+=piles[i]/speed ; //  23%23 =0 ..ie coorect 1 hr 
       else if(piles[i]>speed) count+=piles[i]/speed +1;  // 30>23....piles[i]/speed=1  +1 =2 hr

       if(count>h) return false; 
   }
   
   return true;

}
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n=piles.size();
        int ans=-1;
        int hi=-1;
        for(int i=0;i<n;i++)           
        {
            hi=max(hi,piles[i]);
        }
        int lo=1;     //minimum spees ho skti hai naman khane ki
           // 11 banan ek ghnte m kha skta hai amx

        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;

            if(caneat(mid,piles,h)==true)         // mid represit kr rha speed ko
            {
                ans=mid;
                hi=mid-1;                        // will check kya isse km ke liye bhi aa skta hai
            }
            else
            {
                lo=mid+1;                        //if piche wali is greater ho rhe hour se. so speed bdhao
            }
        }

       return ans; 
    }
};