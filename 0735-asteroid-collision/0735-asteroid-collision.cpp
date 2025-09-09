class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
      int n=asteroids.size();
      stack<int>st;   //[4,7,1,1,2,-3,-7,17,15,-16]

      for(int i=0;i<n;i++)
      {
        if(asteroids[i]<0)  // agr negative no 3 conditions 
        {
            while(st.size()>0 && st.top()>0 && abs(st.top())<abs(asteroids[i]))
            {
                st.pop();
            }
            // if the elmets are qual 
            if(st.size()>0 && st.top()>0 && abs(st.top())==abs(asteroids[i]))
            {
                st.pop();
            }
            else if(st.size()==0 || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
        }
        else
        {
            st.push(asteroids[i]);
        }
      }
      vector<int> ans(st.size());

      for(int i=st.size()-1;i>=0;i--)
      {
        ans[i]=st.top();
        st.pop();
      }
      return ans;

      
        
    }
};