class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n=asteroids.size();
        stack<int>st;

        for(int i=0;i<n;i++)
        {
          // if the no is neagtive 
          if(asteroids[i]<0)
          {
            while(st.size()>0 && st.top()>0 && abs(st.top())<abs(asteroids[i]))
            {
                st.pop();
            }
            // if the incoming neagtive no is of same magnitude 
            if(st.size()>0 && st.top()>0 && abs(st.top())==abs(asteroids[i]))
            {
                st.pop();
            }
            else if(st.size()==0 || st.top()<0)
            {
              st.push(asteroids[i]);
            }
            
        }
          else
          {
            st.push(asteroids[i]);   // if positive simply push 
          }
        }
          vector<int>ans(st.size());
        // pop all the reamaing elmnts out of the stack 
        for(int i=st.size()-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }
      return ans;
        
    }
};