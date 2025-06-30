class Solution {
public:
   bool check(long long mid,vector<int>& time, int totalTrips)
   {
       int n=time.size();
       long long count=0;      // no of trips jo time aayegi uske liye mr lenge.
       for(int i=0;i<n;i++)
       {
        count+=mid/(long long) time[i];   
       }
       if(count>=totalTrips) return true;// atleast total trip he have to make
       else return false;
   }


    long long minimumTime(vector<int>& time, int totalTrips)
    {
        int n= time.size();
        int mx=-1;
        for(int i=0;i<n;i++)
        {
            mx= max(mx,time[i]);
        }
        // bs yhan time pr lagega.
        long long lo=1; // atleast 1 trip to maregahi
        long long hi=(long long) mx*(long long)totalTrips;   //itna trip to maarni hi hai if 3rd bus ke hissab se chlen 
        long long ans=-1;
        while(lo<=hi)
        {
            long long mid=lo+(hi-lo)/2;
            //check fn
            if(check(mid,time,totalTrips))
            {
              ans=mid;
              hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;        
    }
};