int robot(int A, int B)
{
    if(A == 1 || B == 1)
        return 1;
    else
    return robot(A-1, B) + robot(A, B-1);
}
int Solution::uniquePaths(int A, int B) {
    int res = robot(A, B);
    return res;
}
