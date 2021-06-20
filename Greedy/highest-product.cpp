int Solution::maxp3(vector<int> &A)
{
    int res = INT_MIN;
    sort(A.begin(),A.end());
    //printVec(A);

    int N = A.size();
    res = A[N-1]*A[N-2]*A[N-3];

    int neg = A[0]*A[1]*A.back();
    res = max(res,neg);

    return res;
}
