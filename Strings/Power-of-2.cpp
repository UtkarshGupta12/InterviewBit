#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

void divideby2(vector<int> &A)
{
    for(int i=0;i<A.size();i++)
    {
        A[i+1] += (A[i]%2)*10;
        A[i] = A[i]/2;
        //if(A[0]==0)
          //  A.erase(A.begin());
    }
}

int power(string N) 
{
    //cout << "N.back() : "<<N.back()<<endl;
    //cout << "N.back() - '0' : "<<N.back()-'0'<<endl;
    
    if (N[0]-'0' < 0) 
        return 0;
    else if(N.back()-'0'==1||N.back()-'0'==3||N.back()-'0'==5||N.back()-'0'==7||N.back()-'0'==9)
        return 0;
    else if(N.size()==1&&(stoi(N)==2||stoi(N)==4||stoi(N)==8))
        return 1;
    
    vector<int> A;
    for(int i=0;i<N.size();i++)
        A.push_back(N[i]-'0');
    printVec(A);
    
    while(A.back()==2||A.back()==4||A.back()==6||A.back()==8||A.back()==0)
    {
        divideby2(A);
        printVec(A);    
    }
    
    if(A.back()==3||A.back()==5||A.back()==7||A.back()==9)
        return 0;
    
    int ind = -1;
    for(int i = 0; i < A.size(); i++) 
    {
        if (A[i] != 0) 
        {
            ind = i;
            break;
        }
    }
    
    cout << ind << endl;
    A.erase(A.begin(),A.begin()+ind);
    
    printVec(A);
    
    if(A.size()==1&&A[0]==1)
        return 1;
        
    return 0;
}

int main()
{
    string str = "590295810358705700000";
    cout << "Ques : "<< str << endl;
    cout << power(str)<<endl;
    
}
