/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/
vector<int> Solution::plusOne(vector<int> &A) {
    int c = 1, i;
    vector<int> result;
    for(i = A.size()-1; i >= 0; i--)
    {
        A[i]+= c;
        if(A[i] > 9)
        {
            c = 1;
            A[i] = 0; 
        }
        else
        {
            c = 0;
        }
        result.push_back(A[i]);
    }
    if(c == 1)
    {
        result.push_back(c);
    }
    reverse(result.begin(), result.end());
    vector<int>:: iterator it;
    int count = 0;
    vector<int> result1;
    for(it = result.begin(); it != result.end(); it++)
    {
        //cout << *it << "h";
        if(*it == 0 && count == 0)
        {
            
        }
        else
        {
           result1.push_back(*it);
           count++;
        }
    }
    return result1;
}
