/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/
int Solution::isMatch(const string A, const string B) {
    
    int size1 = A.size() , size2 = B.size() , i , j ; 
    bool dp[size1 + 1][size2 + 1] ;
    dp[0][0] = true ;
    dp[0][1] = false ;
    for( i = 2 ; i <= size2 ; i++ )
    {
        if( B[i - 1] == '*' )
            dp[0][i] = dp[0][i - 2] ;
        else
           dp[0][i] = false ;
    }
    for( i = 1 ; i <= size1 ; i++ )
    {
        dp[i][0] =  false ; 
    }
    for( i = 1 ; i <= size1 ; i++ )
    {
        for( j = 1 ; j <= size2 ; j++ )
        {
            if(A[i - 1] == B[j - 1] || B[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1] ;
            else if( B[j - 1] == '*' )
            {
                dp[i][j] = dp[i][j-2];
                if( B[j - 2] == A[i - 1] || B[j - 2] == '.' )
                    dp[i][j] = (dp[i][j] || dp[i - 1][j]) ;
            }
                
            else
                dp[i][j] = false ;
            
        }
    }
    return dp[size1][size2] ;
}

