int Solution::solve(vector<int> &A,int K)
{
    int res=0;
    make_heap(A.begin(),A.end());
    //printHeap(A);

    for(int i=0;i<K;i++)
    {
        res+=A.front();
        A.front()--;
        make_heap(A.begin(),A.end());    
        //cout<<endl;printHeap(A);
    }

    return res;
}
