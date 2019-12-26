int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    vector<int> B = A;
    sort(B.begin(),B.end());
    int max = 0;
    for(int i=0;i<B.size()-1;i++){
       if(B[i+1]-B[i] > max)
       max = B[i+1]-B[i];
    }
return max;
    /*int max = A[0], min = A[0], i, diff, max1 = 0, range, m, n, k = 0, a, b, j;
    
    if(A.size() < 2)
    {
        return 0;
    }
    for(i = 1; i < A.size(); i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }
        if(min > A[i])
        {
            min = A[i];
        }
    }
    range = max - min +1;
    vector<int> bucket[range];
    for(i = 0; i < (max - min +1); i++)
    {
        bucket[i].push_back(0);
    }
    for(i = 0; i < A.size(); i++)
    {
        bucket[A[i]-min].push_back(A[i]);
    }
    for(i = 0; i < (max-min+1); i++)
    {
        if(bucket[i].size() == 1)
        {
            i++;
        }
        else
        {
            m = i;
            k++;
            break;
        }
        
    }
    a = bucket[i][1];
    j = i + 1;
    for(i = j; i < (max - min + 1);)
    {
        if(bucket[i].size() == 1)
        {
            i++;
        }
        else 
        {
            b = bucket[i][1];
            diff = (b - a);
            if(max1 < diff)
            {
                max1 = diff;
            }
            a = bucket[i][1];
            i++;
        }
    }
    return diff;*/
    
}
