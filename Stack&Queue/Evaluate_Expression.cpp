/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
Seen this question in a real interview before
*/
int Solution::evalRPN(vector<string> &A) {
    stack<int>s;
    int a, b, c, i = 0;
    while(i < A.size())
    {
        if(A[i].compare("+") == 0 || A[i].compare("-") == 0 || A[i].compare("*") == 0 || A[i].compare("/") == 0)
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            if(A[i].compare("+") == 0)
                c = a+b;
            else if(A[i].compare("-") == 0)
                c = b-a;
            else if(A[i].compare("*") == 0)
                c = b*a;
            else if(A[i].compare("/") == 0)
                c= b/a;
            s.push(c);
        }
        else
        {
            s.push(stoi(A[i]));
        }
        i++;
    }
    a = s.top();
    return a;
}
