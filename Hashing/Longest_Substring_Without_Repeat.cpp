/*
Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/
int Solution::lengthOfLongestSubstring(string A) {
    map<char, int>mp; 
    int i, diff, max = -1, ptr;
    if(A.size() == 1)
    {
        return 1;
    }
    ptr = 0; 
    mp[A[0]] = 0;
    for(i = 1; i < A.size(); i++)
    {
        if(mp.find(A[i]) == mp.end())
        {
            mp[A[i]] = i;
            if(i == A.size()-1)
            {
                diff = (i - ptr + 1);
                if(diff > max)
                {
                    max = diff;
                }
            }
        }
        else
        {
            diff = (i - ptr);
           // cout << "[" << diff << "]";
            if(diff > max)
            {
                max = diff;
            }
            ptr = (mp[A[i]])+1;
         // cout << "|" << ptr << "|";
            mp.clear();
            i = ptr;
            mp[A[ptr]] = ptr;
        }

       // cout << "{" << max << "}";
    }
return max;
}
