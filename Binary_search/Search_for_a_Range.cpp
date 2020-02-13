/*
Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].



Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

 Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints

1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]
Seen this question in a real interview before
*/
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v(2);
    v[0] = -1; v[1] = -1;
    int low = 0, high = A.size()-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(A[mid] == B)
        {
            v[0] = mid;
            high = mid-1;
        }
        else if(A[mid] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid-1;
        }
    }
    low = 0; high = A.size()-1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(A[mid] == B)
        {
            v[1] = mid;
            low = mid+1;
        }
        else if(A[mid] > B)
        {
            high = mid - 1;
        }
        else
        {
            low = mid+1;
        }
    }
return v;
}
/*int M_BS_L(vector<int> A, int low, int high, int B)
{
    int mid, res1;
    if(low <= high)
    {
    	mid = (low+high)/2;
    	if(A[mid] == B)
    	{
    		if(mid == low)
    		{
    			return mid;
    		}
    		if(A[mid-1] != A[mid])
    		{
    			return mid;
    		}
    	}
    	if(A[mid] < B)
    	{
    		return M_BS_L(A, mid+1, high, B);
    	}
    	else
    	{
    		return M_BS_L(A, low, mid-1, B);
    	}
    
    }
return -1;
}
int M_BS_R(vector<int> A, int low, int high, int B)
{
    int mid, res1;
    if(low <= high)
    {
    	mid = (low+high)/2;
    	if(A[mid] == B)
    	{
    		if(mid == high)
    		{
    			return mid;
    		}
    		if(A[mid+1] != A[mid])
    		{
    			return mid;
    		}
    	}
    	if(A[mid] > B)
    	{
    		return M_BS_R(A, low, mid-1, B);
    	}
    	else
    	{
    		return M_BS_R(A, mid+1, high, B);
    	}
    
    }
return -1;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int a = M_BS_L(A, 0, A.size()-1, B);
    int b = M_BS_R(A, 0, A.size()-1, B);
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    return res;
}*/
