/*
Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.

NOTE: Solution will fit in a 32-bit signed integer.



Input Format:

The first and the only argument is an integer array A.

Output Format:

Return the highest possible product.

Constraints:

1 <= N <= 5e5

Example:

Input 1:
A = [1, 2, 3, 4]

Output 1:
24

Explanation 1:
2 * 3 * 4 = 24

Input 2:
A = [0, -1, 3, 100, 70, 50]

Output 2:
350000

Explanation 2:
70 * 50 * 100 = 350000
*/
int Solution::maxp3(vector<int> &nums) {
     sort(nums.begin(), nums.end());
        int size = nums.size();
        int p1 = nums[0]*nums[1]*nums[size-1];
        int p2 = nums[size-1]*nums[size-2]*nums[size-3];
        return (p1 < p2)? p2:p1;
}
