/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    multimap<int, int> mp;
    map<int, int> mp1;
    vector<int> res;
    int i, sum, a, b, temp;
    for(i = 0; i < A.size(); i++)
    {
        mp.insert(make_pair(A[i], i));
    }
    multimap<int, int>::iterator itr = mp.begin();
    multimap<int, int>::iterator ptr = --mp.end();
    while(itr != ptr)
    {
        sum = itr->first + ptr->first;
        if(sum == B)
        {
            if(itr->second > ptr -> second)
                mp1[itr -> second + 1] = ptr -> second + 1;
            else
                mp1[ptr -> second + 1] = itr -> second + 1;
            ptr--;
        }
        else if(sum < B)
            itr++;
        else
            ptr--;
    }
    map<int, int>::iterator qtr = mp1.begin();
    if(mp1.begin() == mp1.end())
        return res;
    res.push_back(qtr -> second);
    res.push_back(qtr -> first);
    return res;
}
