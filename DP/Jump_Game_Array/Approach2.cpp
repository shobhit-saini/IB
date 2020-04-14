int Solution::canJump(vector<int> &A) {
    int size = A.size() , i , index  = 0;
    for( i = 0 ; i < size ; i++ )
    {
        if( index < A[i] + i )
            index = A[i] + i ;
        if( index == i && i != size - 1 )
            return 0 ;
    }
    return 1 ;
}
