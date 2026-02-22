class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
       int n= asteroids.size();
       stack<int>st;

       for(int i=0;i<n;i++)
       {
          if(asteroids[i]<0) // when negative then do anythig
          {
            while(st.size()>0 && st.top()>0 && abs(st.top())<abs(asteroids[i])) // smaller hai 
            {
                st.pop();
            }
            if(st.size()>0 && st.top()>0 && abs(st.top())==abs(asteroids[i])) // barabr ho to  
            {
                st.pop();  // or indx+1 to apne app hi ho jyega
            }   
            else if(st.size()==0 || st.top()<0)
            {
                st.push(asteroids[i]);
            }  
          }
          else // positiev simply push in stack
          {
            st.push(asteroids[i]);
          }
       }

       vector<int>ans(st.size()); 

       for(int i=st.size()-1;i>=0;i--)
       {
        ans[i]=st.top();
        st.pop();
       } 

       return ans; 
    }
};