string Solution::reverseString(string A) {
    int n = A.size();
    stack<char> S;
    for(int i=0;i<n;i++)
        S.push(A[i]);
        
    for(int i=0;i<n;i++)
    {
        A[i] = S.top();
        S.pop();
    }
    return A;
}
