vector<int> Solution::lszero(vector<int> &A) {
    int max = INT_MIN, first = -1, second = -1, i, sum = 0, diff;
    vector<int> v;
    map<int, vector<int>>mp;
    for(i = 0; i < A.size(); i++)
    {
        sum += A[i];
        mp[sum].push_back(i);
    }
    map<int, vector<int>>::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++)
    {
        if(itr->first == 0)
        {
            diff =  *(--(itr->second.end())) - 0 + 1;
            if(diff > max)
            {
                first = -1;
                second = *(--(itr->second.end()));
                max = second - first;
            }
            else if(diff == max)
            {
                    first = -1;
                    second = *(--(itr->second.end()));
            }
        }
        else
        {
                diff = *(--(itr->second.end())) - *(itr->second.begin());
                if(diff > max)
                {
                    first = *(itr->second.begin());
                    second = *(--(itr->second.end()));
                    //cout<< second << "?";
                    max = diff;
                }
                else if(diff == max)
                {
                    if(*(itr->second.begin()) < first)
                    {
                        first = *(itr->second.begin());
                        second = *(--(itr->second.end()));
                    }
                }
        }
    }
    for(i = first+1; i <= second; i++)
    {
        v.push_back(A[i]);
    }
    return v;
}
