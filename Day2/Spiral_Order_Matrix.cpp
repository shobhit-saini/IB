/*
Q:Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int k = 0, l = 0, i;
    int last_row = A.size()-1;
    int last_column = A[0].size()-1;
    vector<int> result;
    while(k <= last_row && l <= last_column)
    {
        for(i = l; i <= last_column; i++)
        {
            result.push_back(A[k][i]);
        }
        k++;
        for(i = k; i <= last_row; i++)
        {
            result.push_back(A[i][last_column]);
        }
        last_column--;
        if(k <= last_row)
        {
            for(i = last_column; i >= l; i--)
            {
                result.push_back(A[last_row][i]);
            }
            last_row--;
        }
        if(l <= last_column)
        {
            for(i = last_row; i >= k; i--)
            {
                result.push_back(A[i][l]);
            }
            l++;
        }
    }
    return result;
}
