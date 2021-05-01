int Solution::repeatedNumber(const vector<int> &A) 
{
    vector<int> B;
    B = A;
    sort(B.begin(),B.end());
    int temp;
    for(int i =0;i<B.size();i++)
    {
        temp = abs(B[i]);
        B[temp] = -B[temp];
    }
    
    B[0] *= -1;
    
    vector<int> v; 
    for(int j=0;j<B.size();j++)
    {
        if(B[j] > 0)
        {
            v.push_back(B[j]);
        }
    }
    
    int num = v[0];
    
    if(v.empty()){
        return(-1);
    }
    else{
        return(num);
    }
    
    
}
