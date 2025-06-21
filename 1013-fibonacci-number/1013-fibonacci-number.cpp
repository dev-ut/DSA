class Solution {
public:
int solve(int n)
{
    // abse case 
    if(n<=1)
    {
        return n;   // coz fibo(1)=1 ie n and fibo(0)=0 ie its value is dependent on n
    }
    return solve(n-1)+ solve(n-2);
}
    int fib(int n) 
    {
        return solve(n);
    }
};