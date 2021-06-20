int Solution::bulbs(vector<int> &A)
{
    int count = 0;
    bool toogle = false;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0 && toogle==false)
        {
            A[i]=1;
            toogle = true;
            count++;
        }
        else if(A[i]==1 && toogle==true)
        {
            A[i]=1;
            toogle = false;
            count++;
        }
        else
            continue;
        
        //cout<<"For "<<i<<" -> ";printVec(A);
    }

    return count;
}
