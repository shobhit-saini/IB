/*
Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes. If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:

How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. )
Every node is greater than all its children
Let us take an example of 4 distinct integers. Without loss of generality let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :

         4 
       /  \ 
      3   2 
     / 
    1
         4 
       /  \ 
      2   3 
     / 
    1
        4 
       /  \ 
      3   1 
     / 
    2
These are the only possible 3 distinct max heaps possible for 4 distinct elements.

Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007

Input Constraints : n <= 100

 NOTE: Note that even though constraints are mentioned for this problem, for most problems on InterviewBit, constraints are intentionally left out. In real interviews, the interviewer might not disclose constraints and ask you to do the best you can do. 
Seen this question 
*/
long table[101];
long com[101][101];
long choose(int n, int k)
{
    if(k > n)
        return 0;
    if(n <= 1)
        return 1;
    if(k == 0)
        return 1;
    if(com[n][k] != -1)
    {
        return com[n][k];   
    }
    long result = (choose(n-1, k-1) + choose(n-1, k))%1000000007;
    com[n][k] = result; 
    return result;
}
int getleft(int A)
{
    int h = log10(A)/log10(2);
    int numh = pow(2, h);
    int left = A - (pow(2, h) -1);
    if(left >= numh/2)
        return pow(2, h)-1;
    else
        return pow(2, h) - 1 - (numh/2 - left);
}
long no_max_heap(int A)
{
    if(A <= 1)
        return 1;
    if(table[A] != -1)
        return table[A];
    int k = getleft(A);
    long result = (((choose(A-1, k)*no_max_heap(k))%1000000007)*no_max_heap(A - k - 1)) % 1000000007;
    table[A] = result; 
    return result;
}
long initialize(int A)
{
    int i, j;
    for(i = 0; i <= A; i++)
        table[i] = -1;
    for(i = 0; i <= A; i++)
    {
        for(j = 0; j <= A; j++)
        {
            com[i][j] = -1;
        }
    }
    return (no_max_heap(A))%1000000007;
}
int Solution::solve(int A) {
    return initialize(A)%1000000007;
}
