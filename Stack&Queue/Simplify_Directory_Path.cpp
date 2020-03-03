/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
Seen this question in a real interview before
*/
string Solution::simplifyPath(string A) {
    int i = 0;
    string str, temp, str1;
    stack<char>s;
    while(i < A.size())
    {
        if((A[i] >= 97 && A[i] <= 122))
        {
            s.push(A[i]);
        }
        else if(A[i] == '/')
        {
            if(s.empty())
            {
                s.push('/');
            }
            else if(s.top() != '/')
            {
                s.push('/');
                while(A[i] == '/')
                    i++;
                i--;
            }
        }
        else if(A[i] == '.' &&  A[i+1] == '.')
        {
            if(!s.empty())
            {
                s.pop();
                while(!s.empty() && s.top() != '/')
                    s.pop();
                
            }
            i++;
        }
        i++;
    }
    if(!s.empty() && s.top() == '/')
        s.pop();
    if(s.empty())
        s.push('/');
    while(!s.empty())
    {
        temp = s.top();
        str = str + temp;
        s.pop();
    }
    
    reverse(str.begin(), str.end());
    return str;
}
