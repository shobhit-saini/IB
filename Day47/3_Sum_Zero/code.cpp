vector<vector<int> > Solution::threeSum(vector<int> &A) {
   
    vector< vector<int> >result;
     if(A.size() < 3)
        return result;
    map<vector<int> ,bool> m;
    sort(A.begin(), A.end());
    int left, i = 0, right = A.size()-1, sum;
    while(i < A.size()-1)
    {
        left = i+1;
        right = A.size()-1;
        while(left < right)
        {
            vector<int> row;
            sum = A[i] + A[left] + A[right];
            if(sum == 0)
            {
                row.push_back(A[i]);
                row.push_back(A[left]);
                row.push_back(A[right]);
                    if(m.find(row)==m.end())
                   {
                        m[row]++;
                        result.push_back(row);
                   }
                    left++;
                    right--;
            }
            if(sum > 0)
                right--;
            else if(sum < 0)
                left++;

        }
        i++;
    }
    
    return result;
}
