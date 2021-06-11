vector<int> Solution::equal(vector<int> &A)
{
    if(A.empty()) return {};
    unordered_map<int,pair<int,int>> ump;
    vector<int> res,ans;
    vector<vector<int>> search;
    int sum = 0;

    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            sum = A[i]+A[j];
            if(ump.find(sum)!=ump.end())
            {
                //A[A1] + A[B1] = A[C1] + A[D1] 
                //A1 < B1, C1 < D1 || A1 < C1, B1 != D1, B1 != C1 
                int A1 = ump[sum].first;
                int B1 = ump[sum].second;
                int C1 = i;
                int D1 = j;

                if(A1<B1 && C1 < D1 && A1<C1 
                        && B1 != D1 && B1 != C1)
                {    
                    vector<int> temp;
                    temp.push_back(A1);
                    temp.push_back(B1);
                    temp.push_back(C1);
                    temp.push_back(D1);
                    search.push_back(temp);
                }   
            }
            else
                ump.insert({sum,make_pair(i,j)});}}

    //cout<<endl;printVecvec(search);
    if(!search.empty()) 
    {
        sort(search.begin(),search.end());
        res = search[0];
    }    
    
    return res;
}
