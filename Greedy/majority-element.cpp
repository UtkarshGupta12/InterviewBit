int Solution::majorityElement(const vector<int> &A)
{
    int count = 1;
    int maj_index = 0;

    for(int i=1;i<A.size();i++)
    {
        if(A[maj_index]==A[i])
            count++;
        else
            count--;

        if(count==0)
        {
            maj_index = i;
            count = 1;
        }
    }

    return A[maj_index];
}
