int Solution::solve(vector<vector<int>> &A)
{
    //Sort the element
    vector<pair<int,int>> pr;

    //Creating Arrivals
    for(int i=0;i<A.size();i++)
        pr.push_back({A[i][0],1});

    //Creating Departures
    for(int i=0;i<A.size();i++)
        pr.push_back({A[i][1],-1});

    sort(pr.begin(),pr.end());
    //printVectorPair(pr);

    //Calculating max_count
    int sum = 0, max_sum = INT_MIN;
    for(int i=0;i<pr.size();i++)
    {
        sum += pr[i].second;
        max_sum = max(sum,max_sum);
    }

    return max_sum;
}
