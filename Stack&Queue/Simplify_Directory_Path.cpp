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
    string str = "", temp = "";
    stack<string>s, s1;
    while(i < A.size())
    {
        if((A[i] >= 97 && A[i] <= 122))
        {
            while((A[i] >= 97 && A[i] <= 122) )
            {
                temp = temp + A[i];
                i++;
               // s.push(A[i]);
            }
            if(i == A.size())
            {
                s.push(temp);
            }
            i--;
        }
        else if(A[i] == '/' || i == A.size())
        {
            if(temp != "")
            {
                s.push(temp);
                temp = "";
            }
        }
        else if(A[i] == '.' &&  A[i+1] == '.')
        {
            if(!s.empty())
            {
                s.pop();
            }
            i++;
        }
        i++;
    }
    if(s.empty())
    {
        str = str + '/';
        return str;
    }
    while(!s.empty())
    {
        s1.push(s.top());
        s.pop();
    }
    while(!s1.empty())
    {
        str = str + '/';
        str = str + s1.top();
        s1.pop();
    }
    return str;
