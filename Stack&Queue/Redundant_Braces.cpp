/*
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.



Input Format

The only argument given is string A.
Output Format

Return 1 if string has redundant braces, else return 0.
For Example

Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"
Output 2:
    0
    Explanation 2:
        (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
*/
int Solution::braces(string A) {
    stack <int> s;
    int i = 0;
    s.push(A[i]);
    i++;
    while(i < A.size())
    {
        if(A[i] == '*' || A[i] == '/' || A[i] == '-' || A[i] == '+' || A[i] == '(')
        {
            s.push(A[i]);
           
        }
        else if(A[i] == ')')
        {
            if(s.top() == '(')
                return 1;
            while(s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
        i++;
    }
    return 0;
}
