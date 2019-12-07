void Solution::setZeroes(vector<vector<int> > &A) {
    int i, j, row_flag = 0, col_flag = 0;
    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < A[i].size(); j++)
        {
            if(i == 0 && A[i][j] == 0)
            {
                row_flag  = 1;
            }
            if(j == 0 && A[i][j] == 0)
            {
                col_flag = 1;
            }
            if(A[i][j] == 0)
            {
                A[0][j] = 0;
                A[i][0] = 0;
            }
            
        }
    }
    for(i = 1; i < A.size(); i++)
    {
        for(j = 1; j < A[i].size(); j++)
        {
            if(A[0][j] == 0 || A[i][0] == 0)
            {
                A[i][j] = 0;
            }
        }
    }
    if(row_flag == 1)
    {
        for(i = 0; i < A[0].size(); i++)
        {
            A[0][i] = 0;
        }
    }
    if(col_flag == 1)
    {
        for(i = 0; i < A.size(); i++)
        {
            A[i][0] = 0;
        }
    }
}
