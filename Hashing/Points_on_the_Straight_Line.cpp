/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])

Seen this question in a real interview before
*/
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<pair<double, double>, int> mp;
    int i, j, maxi = -1;
    double m, c;
    map<pair<double, double>,int>::iterator itr;
    if(A.size() < 2)
    {
        return A.size();
    }
    for(i = 0, j = 0; i < A.size(); i++)
    {
        for(j = 0; j < A.size(); j++)
        {
            if(i != j)
            {
                if(A[j] - A[i] == 0)
                {
                    m = INT_MAX;
                    c = 0;
                }
                else
                {
                    m = (double)(B[j] - B[i])/(A[j] - A[i]);
                    c = ((double)B[i] - m*(double)A[i]);
                }
                pair<double, double>temp = {m , c};
                mp[temp]++;
            }
        }
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(maxi < itr->second)
            {
                maxi = itr -> second;
            }
        }
        mp.clear();
    }
    return maxi+1;
}
