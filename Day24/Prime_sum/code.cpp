int check_prime(int A)
{
    int flag = 0, i;
    for(i = 2; i <= A/2; i++)
    {
        if(A % i  == 0)
        {
            flag = 1;
            return 0;
        }
    }
    return 1;
}
vector<int> Solution::primesum(int A) {
    vector<int> set;
    int B, i;
    for(i = 2; i < A; i++)
    {
        if(check_prime(i))
        {
            B = A-i;
            if(check_prime(B))
            {
                set.push_back(i);
                set.push_back(B);
                break;
            }
        }
    }
    return set;
}
