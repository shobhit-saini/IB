/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
Seen this question in a real interview before
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int sum, i , j;
    vector<int> v;
    multimap<int, int>mp;
    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < B.size(); j++)
        {
            sum = A[i] + B[j];
            mp.insert(make_pair(sum, 1));
        }
    }
    i = 0;
    multimap<int, int>:: reverse_iterator itr;
    for(itr = mp.rbegin(); itr != mp.rend(); itr++)
    {
        if(i > A.size()-1)
            break;
        v.push_back(itr -> first);
        i++;
    }
    return v;
}
