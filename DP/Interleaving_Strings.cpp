/*
Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
Seen this question in a real interview before
*/
int Solution::isInterleave(string A, string B, string C) {
    
    int size1 = s1.size() , size2 = s2.size() , size3 = s3.size() , i , j = 0 , dp[size1 + 1][size2 + 1];
        if( size1 == 0 && size2 == 0 && size3 == 0 )
            return 1 ; 
        if( (size1 + size2) != size3 )
            return 0;
        
        dp[0][0] = 1 ;
        
        j = 0;
        for( i = 1 ; i <= size2 ; i++ )
        {
            if( s3[j] == s2[i - 1] )
            {
                dp[0][i] = dp[0][i - 1] ;
            }
            else
            {
                dp[0][i] = 0 ;
            }
            j++;
        }
        
        j = 0 ;
        for( i = 1 ; i <= size1 ; i++ )
        {
            if( s3[j] == s1[i - 1] )
            {
                dp[i][0] = dp[i - 1][0] ;
            }
            else
            {
                dp[i][0] = 0 ;
            }
            j++ ;
        }
        
        int k ;
        for( i = 1 ; i <= size1 ; i++ )
        {
            k = i ;
            for( j = 1 ; j <= size2 ; j++ )
            {
                if( s1[i - 1] == s3[k] && s2[j - 1] == s3[k] )
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] ;
                }
                else if( s1[i - 1] == s3[k] )
                {
                    dp[i][j] = dp[i - 1][j] ;
                }
                else if( s2[j - 1] == s3[k] )
                {
                    dp[i][j] = dp[i][j - 1] ;
                }
                else
                {
                    dp[i][j] = 0 ;
                }
                k++ ;
            }
        }
        for( i = 0 ; i <= size1 ; i++ )
        {
            for( j = 0 ; j <= size2 ; j++ )
            {
                cout << dp[i][j] << " " ;
            }
            cout << "\n" ;
        }
        return dp[size1][size2] ;
    
}
