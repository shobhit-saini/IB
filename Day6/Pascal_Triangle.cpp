/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
*/
vector<vector<int> > Solution::solve(int A) {
    int i, j;
    int a;
    vector<vector<int>> result(A);
    for(i = 0; i < A; i++)
        {
            for(j = 0; j <= i; j++)
            {
                if(i == j || j == 0)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j-1]+ result[i-1][j]);
            }
        }
    return result;
}
