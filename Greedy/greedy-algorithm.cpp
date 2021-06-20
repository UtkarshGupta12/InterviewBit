void ReverseEveryElement(vector<vector<int>> &A)
{
    for(int i=0;i<A.size();i++)
    {
        reverse(A[i].begin(),A[i].end());
    }}

int solve(vector<vector<int>> &A)
{
    //Reverse Every Element in Array 
    ReverseEveryElement(A);
    sort(A.begin(),A.end());
    ReverseEveryElement(A);
    printVecvec(A);

    //Deleting arrays 
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i][1]<=A[i+1][1] && A[i][1]>=A[i+1][0])
        {
            A.erase(A.begin()+i+1);
            i--;
            cout<<endl;printVecvec(A);
        }
    }

    return A.size();
}
