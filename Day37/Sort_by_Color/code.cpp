void Solution::sortColors(vector<int> &A) {
    int i, temp, j = 0;
    for(i = 0; i < A.size(); i++)
    {
        if(A[j] == 0)
        {
            j++;
        }
        else
        {
            while(i < A.size() && A[i] != 0)
            {
                i++;
            }
            if(i == A.size())
            {
                break;
            }
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j++;
        }
    }
    for(i = j; i < A.size(); i++)
    {
        if(A[j] == 1)
        {
            j++;
        }
        else
        {
            while(i < A.size() && A[i] != 1)
            {
                i++;
            }
            if(i == A.size())
            {
                break;
            }
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            j++;
        }
    }
}
