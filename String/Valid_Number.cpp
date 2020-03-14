/*
Please Note:
Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem
*/
int Solution::isNumber(const string A) {
    int size = A.length(), flag = 0, i, flag1 = 0, j = 0, flag2 = 0, flag3 = 0;
    while(A[j] == ' ')
    {
        j++;
    }
    if(j == A.length())
        return 0;
    if(A[size-1] == '.')
        return 0;
    if(A[size-1] == 'e')
        return 0;
    i = j;
    if(A[i] == '+' || A[i] == '-')
    {
        i++;
        if(i == A.length())
            return 0;
    }
    while(i < A.length())
    {
        if(A[i-1] != 'e' && (A[i] == '+' || A[i] == '-'))
        {
            return 0;
        }
        i++;
    }
    i = j;
    while(i < A.length())
    {
       
        if(A[i] == '.')
        {
            if(flag2 == 1)
                return 0;
            flag2 = 1;
        }
            
        i++;
    } 
    for(i = j; i < A.length(); i++)
    {
        if(flag3 == 1)
        {
            return 0;
        }
        else if(A[i] == 'e')
        {
            if(A[i-1] == '.')
                return 0;
            if(flag == 1)
                return 0;
            flag = 1;
        }
        else if(flag == 1  && A[i] == '.')
            return 0;
        else if(A[i] == '-' || A[i] == '+')
        {}
        else if(A[i] == '.')
        {
            
        }
        else if(A[i] == ' ')
        {
            while(i < A.length() && A[i] == ' ')
            {
                i++;
            }
            i--;
            flag3 = 1;
        }
        else if((A[i] < 48 || A[i] > 57))
        {
            return 0;
        }
    }
    return 1;
    
}
