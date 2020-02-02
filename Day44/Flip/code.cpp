vector<int> Solution::flip(string A) {
    vector<int> result;
    int max = 0, difference = 0, i, start = 0, end = 0, left = 0;
    for(i = 0; i < A.length(); i++)
    {
        if(A[i] == '0')
            break;
    }
    if(i == A.length())
        return result;
    for(i = 0; i < A.length(); i++)
    {
        if(A[i] == '0')
            difference += 1;
        else
            difference -= 1;
        if(difference < 0)
        {
            left = i + 1;
            difference = 0;
        }
        if(difference > max)
        {
            max = difference;
            start = left + 1;
            end = i + 1;
        }
    }
    result.push_back(start);
    result.push_back(end);
    return result;
}

