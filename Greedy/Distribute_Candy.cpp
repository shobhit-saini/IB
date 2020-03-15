/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
Seen this question in a real interview before
*/
int Solution::candy(vector<int> &A){
    vector<int> v1(A.size(),1);
    vector<int> v2(A.size(),1);
    int i, total = 0, curr = 1, pos = 0;
    for(i = 1; i < A.size(); i++)
    {
        if(A[i] > A[i -1])
        {
            v1[i] = v1[i-1] + 1;
        }
    }
    for(i = A.size()-2; i >= 0 ; i--)
    {
        if(A[i] > A[i +1])
        {
            v2[i] = v2[i+1] + 1;
        }
    }
    for(i = 0; i < A.size(); i++)
    {
        total += (v1[i] >= v2[i])? v1[i] : v2[i];
    }
    return total;
}
/*int Solution::candy(vector<int> &A) {
    int i, total = 1, curr = 1, pos = 0;
    for(i = 1; i < A.size(); i++)
    {
        if(A[i] > A[i-1])
        {
            curr++;
            total += curr;
            pos = i;
        }
        else if(A[i] < A[i-1])
        {
                curr--;
                if(curr == 0)
                {
                    curr = 1;
                    total = total + curr + i - pos;
                }
                else if(i == A.size()-1)
                    total++;
                else if((i+1) < A.size() && A[i] < A[i+1])
                {
                    curr = 1;
                    total = total + curr;
                }
                
                else
                    total += curr;
            
        }
        else if(A[i] == A[i-1])
            total += curr;
    }
    return total;
}*/
