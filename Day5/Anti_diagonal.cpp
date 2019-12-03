/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i, j, k = 0, a;
    vector<vector<int>> result(2*A.size()-1);
    for(i = 0; i < A.size(); i++)
    {
        k = i;
        for(j = 0 ; j < A.size(); j++)
        {
            result[k].push_back(A[i][j]); 
            k++;
        }
    }
    return result;
}
