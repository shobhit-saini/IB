/*Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14
At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7

Seen this question in a real interview before*/
int Solution::nchoc(int A, vector<int> &B) {
    map<int,int>mp;
    long int c = 0, temp;
    int i; 
    for(i = 0; i < B.size(); i++)
    {
        mp[B[i]] += 1;
    }
    map<int,int>:: iterator itr;
    for(i = 0; i < A; i++)
    {
        itr = --mp.end();
        temp = itr -> first;
        c = (c + temp)%1000000007;
        if(mp[temp] > 1)
            mp[temp]--;
        else
            mp.erase(temp);
        temp = floor(temp/2);
        mp[temp] += 1;
    }
    return c%1000000007;
}
