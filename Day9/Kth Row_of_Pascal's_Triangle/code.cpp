vector<int> Solution::getRow(int A) {
    vector<vector<int>> result(A+1);
    int i, j;
    for(i = 0; i <= A; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(i == j || j == 0)
            {
                result[i].push_back(1);
            }
            else
            {
                result[i].push_back(result[i-1][j] + result[i-1][j-1]);
            }
        }
    }
    return(result[A]);
}
