int Solution::solve(vector<string> &A) {
    int i;
    float first = stof(A[0]), second = stof(A[1]), third = stof(A[2]);
    for(i = 3; i < A.size(); i++)
    {
        if((first+second+third) <2 && (first+second+third)>1)
        {
            return 1;
        }
        else if(first+second+third >=2)
        {
            if(first > second && first > third)
            {
                first = stof(A[i]);
            }
            else if(second > first && second > third)
            {
                second = stof(A[i]);
            }
            else if(third > first && third > second)
            {
                third = stof(A[i]);
            }
        }
        else if(first+second+third <= 1)
        {
             if(first < second && first < third)
            {
                first = stof(A[i]);
            }
            else if(second < first && second < third)
            {
                second = stof(A[i]);
            }
            else if(third < first && third < second)
            {
                third = stof(A[i]);
            }
        }
    }
    if(first+second+third < 2 && first+second+third >1)
        return 1;
    return 0;
}    
