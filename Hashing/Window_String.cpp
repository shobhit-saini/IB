/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).
Seen this question in a real interview before
*/
string Solution::minWindow(string A, string B) {
    map<char, int>mp;
    map<int, int>mp1;
    int start_pointer = 0, i, j, k = 0, l, flag = 0, first, last;
    string str = "";
    //If there is no such window in S that covers all characters in T, return the empty string ''.//
    for(i = 0; i < B.size(); i++)
    {
        mp[B[i]] += 1;
    }
    for(i = 0; i < A.size(); i++)
    {
        if(mp.find(A[i]) != mp.end())
        {
            mp[A[i]] -= 1;
        }
    }
    
    map<char, int>::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++)
    {
            if(itr -> second > 0)
            {
                flag = 1;
                break;
            }
    }
    if(flag == 1)
    {
        return str;
    }
    ////////////////////////////////////////////////////////////////////////////
    mp.clear();
    for(i = 0; i < B.size(); i++)
    {
        mp[B[i]] += 1;
    }
    
    for(i = 0; i < A.size(); i++)
    {
        if(mp.find(A[i]) != mp.end())
        {
            mp[A[i]] -= 1;
        }
        else
        {
            continue;
        }
        flag = 0;
        //map<char, int>::iterator itr;
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr -> second > 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            continue;
        }
        else
        {
            for(j = start_pointer; j <= i; j++)
            {
                if(mp.find(A[j]) != mp.end())
                {
                    if(mp[A[j]] < 0)
                    {
                        mp[A[j]] += 1;
                        continue;
                    }
                    else 
                    {
                        start_pointer = j;
                        mp1[k] = start_pointer;
                        //cout << "{" << mp1[k];
                        k++;
                        mp1[k] = i;
                        //cout << "," << mp1[k] << "}";
                        k++;
                        //cout << "[" << A[j] << "]";
                        mp[A[j]] += 1;
                       break;
                    }
                }
            }
            for(l = j+1; l <= i; l++)
            {
                if(mp.find(A[l]) != mp.end())
                {
                    start_pointer = l;
                    break;
                }
            }
        }
        
    }
    int min = INT_MAX, diff;
    for(i = 0; i < mp1.size(); i += 2)
    {
        diff = abs(mp1[i] - mp1[i+1]); 
        if(diff < min)
        {
            min = diff;
            first = mp1[i];
            last = mp1[i+1];
        }
    }
    for(i = first; i <= last; i++)
    {
        str += A[i];
    }
    return str;
}
