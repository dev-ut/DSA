class Solution {
public:
void solve(vector<string>&fans,string ans,int openc,int closec,int n)
{
     // base case  close ka count agr 
     if(closec==n)
     {
        fans.push_back(ans);
        return ;
     }

    if(openc<n) solve(fans,ans+"(",openc+1,closec,n);// incle this "(" bracket
    if(closec<openc) solve(fans,ans+")",openc,closec+1,n);// incle this "(" bracket
}
    vector<string> generateParenthesis(int n) 
    {
        vector<string>fans;
        solve(fans,"",0,0,n);
        return fans;
        
    }
};