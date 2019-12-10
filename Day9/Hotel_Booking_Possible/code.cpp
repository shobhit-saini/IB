bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int i = 0, j = 0, k = 0;
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    while(i < arrive.size() && j < depart.size())
    {
        if(arrive[i] < depart[j])
        {
            k++;
            if(k > K)
            {
                return false;
            }
            i++;
        }
        else
        {
            k--;
            j++;
        }
        
    }
    return true;
}
