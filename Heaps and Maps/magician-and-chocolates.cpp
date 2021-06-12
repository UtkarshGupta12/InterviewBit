#define M 1000000007

int Solution::nchoc(int B, vector<int> &A)
{
    long long res=0;
    make_heap(A.begin(),A.end());
    for(int i=0;i<B;i++)
    {
        res+=A.front();
        int temp = A.front();
        pop_heap(A.begin(), A.end());
        A.pop_back();
        A.push_back(floor(temp/2));
        push_heap(A.begin(),A.end());
        //printHeap(A);cout<<endl;
    }

    return res%M;
}
