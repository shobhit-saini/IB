string Solution::countAndSay(int A) {
    int i, j, flag = 0, count = 0;
    string temp, seq1 = "", var;
    string seq = "1";
    for(i = 1; i < A; i++)
    {
        seq1 = "";
        for(j = 0; j < seq.length(); j++)
        {
            
            if(flag == 0)
            {
                temp = seq[j];
                flag =1;
            }
            var = seq[j];
            if(temp.compare(var) == 0)
            {
                count++;
            }
            else 
            {
                seq1 += to_string(count);
                seq1 += temp;
                flag = 0;
                count = 0;
                j--;
            }
        }
        seq1 += to_string(count);
        seq1 += temp;
        seq = seq1;
        flag = 0;
        count = 0;
    }
 
    return seq;
}
