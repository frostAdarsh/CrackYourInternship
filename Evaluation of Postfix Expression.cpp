//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        for (char ch : S)
        {
            
            if (isdigit(ch))
            {
                st.push(ch - '0');
            }
           
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                int operand2 = st.top(); st.pop();
                int operand1 = st.top(); st.pop();
                
                switch (ch)
                {
                    case '+': st.push(operand1 + operand2); break;
                    case '-': st.push(operand1 - operand2); break;
                    case '*': st.push(operand1 * operand2); break;
                    case '/': st.push(operand1 / operand2); break;
                }
            }
        }
        

        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends