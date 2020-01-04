vector<int> Solution::findPerm(const string A, int B) {
    int arr[B], i;
    vector<int> sol;
    for(i = 1; i <= B; i++)
    {
        arr[i-1] = i;
    }
    int a = 0, b = B-1;
    for(i = 0; i <= A.size(); i++)
    {
        if(A[i] == 'I')
        {
            sol.push_back(arr[a]);
            a++;
        }
        else if(A[i] == 'D')
        {
            sol.push_back(arr[b]);
            b--;
        }
    }
    sol.push_back(arr[a]);
    return sol;
}
