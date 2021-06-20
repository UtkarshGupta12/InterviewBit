vector<int> Solution::solve(vector<int> &A,int B)
{
    map<int,int> mp;
    int N = A.size();

    //Creating map with value and index
    for(int i=0;i<A.size();i++)
        mp[A[i]] = i;    
    //printMap(mp);cout<<endl;    

    //Swapping Pairs
    auto it = mp.rbegin();

    for(int i=0;i<N;i++)
    {
        if(B>0)
        {    
            if(A[i]!=it->first)
            {    
                int temp = it->second; 
                swap(A[i],A[it->second]);
                mp[A[i]] = i;
                mp[A[temp]] = temp;
                ++it;
                B--;
            }
            else
                ++it;
            //printVec(A);
        }
        else
            break;    
            //printMap(mp);cout<<endl; 
    }

    return A;
}
