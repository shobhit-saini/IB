int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size() < 3)
    {
        return 0;
    }
    sort(A.begin(), A.end());
    int i = 0, left = i, right = A.size()-1, minn, maxx, sum, diff, min_diff, sum1;
    min_diff = INT_MAX;
    while(i < A.size()-2)
    {
        left = i+1;
        right = A.size()-1;
        while(left < right)
        {
            sum = A[i] + A[left] + A[right];
            diff = abs(B-sum);
            if(sum == B) 
                return B;
            if(diff < min_diff)
            {
                min_diff = diff;
                sum1 = sum;
            }
            
            if(sum < B)
                left++;
            else 
                right--;
        }
        i++;
    }
    return sum1;
}
