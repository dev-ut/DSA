class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
      int n=asteroids.size();
      stack<int>st;

      for(int i=0;i<n;i++)  //[4,7,1,1,2,-3,-7,17,15,-16]
      {
        if(asteroids[i]<0) // ie agr negative elment hai to 
        {
            while(st.size()>0 && st.top()>0 && abs(st.top())<abs(asteroids[i])) // we will pop the elements until 
            {
                st.pop();
            }
            // if the mangintude of postive nad negative elment are equal pop and get indx+1
            if(st.size()>0 && st.top()>0 && abs(st.top())==abs(asteroids[i]))
            {
                st.pop();
            }
            else if(st.size()==0 || st.top()<0)
            {
                st.push(asteroids[i]);
            }
        }
        else  // if sare posistives elment hai to just push back  
        {
           st.push(asteroids[i]);
        }
      }

      // ab ise vecto mai wapas denge
       vector<int> ans(st.size());

      for(int i=st.size()-1;i>=0;i--)
      {
        ans[i]=st.top();
        st.pop();
      }
      return ans;
    }
};