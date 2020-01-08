vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> >result(A, vector<int> (A));
    int k = 0, l = 0, count = 1, i;
    int last_row = A-1, last_col = A-1;
    while(k <= last_row && l <= last_col)
    {
        for(i = l; i <= last_col; i++)
        {
            result[k][i] = count;
            count++;
        }
        k++;
        for(i = k; i <= last_row; i++)
        {
            result[i][last_col] = count;
            count++;
        }
        last_col--;
        if(k <= last_row)
        {
            for(i = last_col; i >= l; i--)
            {
                result[last_row][i] = count;
                count++;
            }
            last_row--;
        }
        if(l <= last_col)
        {
           for(i = last_row; i >= k; i--)
           {
               result[i][l] = count++;
           }
           l++;
        }
    }
    return result;
}
