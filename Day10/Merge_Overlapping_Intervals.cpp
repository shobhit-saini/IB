/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compareInterval(Interval i1, Interval i2)
 {
     return (i1.start <= i2.start);
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i, k = 0, end, start;
    vector<Interval> result;
    Interval var;
    sort(A.begin(), A.end(), compareInterval);
    for(i = 0; i < A.size(); i++)
    {
       var.start = A[i].start;
       var.end = A[i].end;
       while(i+1 < A.size() && var.end >= A[i+1].start)
       {
           var.end = (var.end > A[i+1].end)? var.end : A[i+1].end;
           i++;
       }
       if(i == A.size())
       {
           var.end = (var.end > A[i].end)? var.end: A[i].end;
       }
       result.push_back(var);
    }
    return result;
}

