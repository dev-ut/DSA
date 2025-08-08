class Solution {
public:
    // Ye function operator ke according operation perform karega
    int operate(int n1, int n2, string opr)
    {
        if(opr == "+") return n1 + n2;
        else if(opr == "-") return n1 - n2;
        else if(opr == "*") return n1 * n2;
        else return n1 / n2;
    }

    int evalRPN(vector<string>& token) 
    {
        stack<int> st;

        for(int i = 0; i < token.size(); i++)
        {
            // Check karo agar current token operator hai
            if(token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/")
            {
                int n1 = st.top(); st.pop();   // pehle wala nikal lo (ye right operand hoga)
                int n2 = st.top(); st.pop();   // fir second operand

                int result = operate(n2, n1, token[i]);  // n2 op n1 ka operation
                st.push(result);  // result ko dubara stack me daal do
            }
            else 
            {
                // Agar number hai to usko int me convert karke stack me daal do
                st.push(stoi(token[i]));
            }
        }

        // Final result top of stack me bacha hoga
        return st.top();
    }
};
