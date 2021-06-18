//WORKS FOR UNIQUE VALUES ONLY

vector<int> order(vector<int> &A, vector<int> &B) 
{   
    int inf = INT_MAX;
    int N = A.size();
    vector<int> res;

    //Creating a vector of same size
        for(int i=0;i<N;i++)
            res.push_back(inf);

    //Creating a Pair
        vector<pair<int,int>> pr;
        for(int i=0;i<N;i++)
            pr.push_back(make_pair(A[i],B[i]));
        sort(pr.begin(),pr.end());
        cout<<"Pairs    : ";printVectorElements(pr);

    //Creating a sorted array of A
        vector<int> A_sorted;
        A_sorted = A;
        sort(A_sorted.begin(),A_sorted.end());
        cout<<"Sorted A : ";printVec(A_sorted);

    //Creating a vector of smaller elements
        vector<int> smaller;
        for(int i=0;i<N;i++)
            smaller.push_back(i);
        sort(smaller.begin(),smaller.end());
        cout<<"Smaller  : ";printVec(smaller);

    //Preparing Answer
        for(int i=0;i<N;i++)
        {
            int start = pr[i].second;
            int end = start+smaller[i];
            
            while(start<=end)
            {
                if(res[start]==inf)
                {
                    res[start]=A_sorted[i];
                    break;}
                else
                    start++;}}

    return res;
}
