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
    
    int size1 = A.size() , size2 = B.size() , size3 = C.size() , i , j , flag = 0 ;
    j = 0 ;
    multimap<int , int> mp1 , mp2 ;
    for( i = 0 ; i < size3 ; i++ )
    {
        if( A[j] == C[i] )
        {
            mp1.insert(make_pair(A[j] , 1));
            j++ ;
            if( j == size1 )
            {
                flag = 1 ;
                break ;
            }
        }
    }
    if( flag == 0 )
        return 0 ;
    
    j = 0 ;
    flag = 0 ;
    for( i = 0 ; i < size3 ; i++ )
    {
        if( B[j] == C[i] )
        {
            mp1.insert(make_pair(B[j] , 1));
            j++ ;
            if( j == size2 )
            {
                flag = 1 ;
                break ;
            }
        }
    } 
    if( flag == 0 )
        return 0 ;

    for( i = 0 ; i < size3 ; i++ )
    {
        mp2.insert(make_pair(C[j] , 1));
    }
    if( mp1.size() == mp2.size() )
        return 1;
    return 0;
    
}
