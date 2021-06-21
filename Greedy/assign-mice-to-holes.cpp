int Solution::mice(vector<int> &A, vector<int> &B)
{
    int res = INT_MIN;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    //cout<<"A : ";printVec(A);
    //cout<<"B : ";printVec(B);

    for(int i=0;i<A.size();i++)
        res = max(res,abs(A[i]-B[i]));

    return res;
}
