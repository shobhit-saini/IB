vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int i, maxi, j;
    deque<int>dq;
    vector<int> result;
    if(A.size() <= B)
    {
        maxi = A[0];
        for(i = 1; i < A.size(); i++)
        {
            if(maxi < A[i])
                maxi = A[i];
        }
        result.push_back(maxi);
        return result;
    }
    dq.push_back(0);
    for(i = 1; i < B; i++)
    {
        if(A[i] <= A[dq.back()])
        {
            dq.push_back(i);
        }
        else
        {
            while(!dq.empty() && A[i] > A[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    for(i = B; i < A.size(); i++)
    {
        result.push_back(A[dq.front()]);
        while(!dq.empty() && dq.front() <= i-B)
        {
            dq.pop_front();
        }
        if(A[i] <= A[dq.back()])
        {
            dq.push_back(i);
        }
        else
        {
            while(!dq.empty() && A[i] > A[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
    }   
    result.push_back(A[dq.front()]);
    return result;
}
