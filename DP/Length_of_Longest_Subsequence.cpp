/*

*/
int Solution::longestSubsequenceLength(const vector<int> &nums) {
    
        int arr[nums.size()], brr[nums.size()], i, j, max = -1, temp;
        if(nums.size() == 0)
            return 0;
        for(i = 0; i < nums.size(); i++)
        {
            arr[i] = 1;
            brr[i] = 1;
        }
        for(i = 1; i < nums.size(); i++)
        {
            for(j = 0; j <= i; j++)
            {
                if(nums[i] > nums[j])
                    arr[i] = (arr[i] > arr[j]+1) ? arr[i] : arr[j]+1;
            }
        }
        for(i = nums.size()-2; i >= 0; i--)
        {
            for(j = nums.size()-1; j > i; j--)
            {
                if(nums[i] > nums[j])
                    brr[i] = (brr[i] > brr[j] + 1) ? brr[i] : brr[j]+1;
            }
        }
        for(i = 0; i < nums.size(); i++)
        {
            
            temp = arr[i] + brr[i] - 1;
            if(max < temp)
                max = temp;
        }
        return max;
}
