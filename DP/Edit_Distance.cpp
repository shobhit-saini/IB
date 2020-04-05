/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
Seen this question in a real interview before
*/

int Solution::minDistance(string A, string B) {
    
    int size1 = A.size() , size2 = B.size() , dp[size2 + 1][size1 + 1] , i , j ;
    for( i = 0 ; i <= size2 ; i++ )
    {
        for( j = 0 ; j <= size1 ; j++ )
        {
            if( i == 0 || j == 0 )
            {
                if( i == 0 )
                    dp[i][j] = j;
                if( j == 0 )
                    dp[i][j] = i;
            }
            else
            {
                if( A[j-1] == B[i-1] )
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min( dp[i - 1][j - 1] , min( dp[i - 1][j] , dp[i][j - 1] )) + 1;
            }
        }
    }
    return dp[size2][size1];
}
