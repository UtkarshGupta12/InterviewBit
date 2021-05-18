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

int searchInsert(const vector<int> &A, int B) 
{
    int low = 0, high = A.size()-1;

    while(low <= high) 
    {
        int mid = (high + low) / 2;
    //cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;
        
        if(A[mid]==B)
            return mid;  
        else if(A[mid] > B && A[mid-1] < B)
            return mid;
        else if(A[high] < B)
            return high+1;
        else if(A[low] > B)
            return 0;
        else if(A[mid] < B ) 
            low = mid + 1;
        else
            high = mid - 1;
        
    }
    return 0;
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    
    if(n==0 && m%2==1)
        return B[(m/2)];
    else if(n==0 && m%2==0 )
        return ((double)B[m/2]+(double)B[(m/2)-1])/2;
    else if(m==0 && n%2==0 )
        return ((double)A[n/2]+(double)A[(n/2)-1])/2;
    else if(m==0 && n%2==1)
        return A[(n/2)];
    
    if((m+n)%2==1)
    {
        int i = 0;
        int ans = (m+n)/2 + 1;
        cout <<"Position should be at : "<<ans<<endl;
        int al = 0;
        int k;
        
        while(al<ans-1)
        {
            k = B[i];
            al = searchInsert(A,k)+i;
            if(A[al-i]==k && al+1 == ans)
                al++;
            cout <<"Position insert of ["<<k<<"] is at " << al+1 << endl;
            i++;
        }    
        
        if(al+1>ans)
        {
            al=0,i=0;
            while(al<ans-1)
            {
                k = A[i];
                al = searchInsert(B,k)+i;
                if(B[al-i]==k && al+1 == ans)
                    al++;
                cout <<"Position insert of ["<<k<<"] is at " << al+1 << endl;
                i++;
            }
        }    
        return k;        
    }    
    
    else 
    {
        int i=0;
        int ans1 = (m+n)/2;
        int ans2 = (m+n)/2+1;
        cout <<"Position should be between : "<<ans1<<" & "<<ans2<<endl;
        int al = 0;
        
        double k1;
        while(al<ans1-1)
        {
            k1 = B[i];
            al = searchInsert(A,k1)+i;
            if(A[al-i]==k1 && al+1 == ans1)
                al++;
            cout <<"Position insert of ["<<k1<<"] is at " << al+1 << endl;
            i++;
        }    
        
        if(al+1>ans1)
        {
            al=0,i=0;
            while(al<ans1-1)
            {
                k1 = A[i];
                al = searchInsert(B,k1)+i;
                if(B[al-i]==k1 && al+1 == ans1)
                    al++;
                cout <<"Position insert of ["<<k1<<"] is at " << al+1 << endl;
                i++;
            }
        } 
        
        cout << "1st term for median is : "<<k1<<endl<<endl;
        
        double k2;
        al=0;
        i=0;
        
        while(al<ans2-1)
        {
            k2 = B[i];
            al = searchInsert(A,k2)+i;
            if(A[al-i]==k2 && al+1 == ans2)
                al++;
            cout <<"Position insert of ["<<k2<<"] is at " << al+1 << endl;
            i++;
        }    
        
        if(al+1>ans2)
        {
            al=0,i=0;
            while(al<ans2-1)
            {
                k2 = A[i];
                al = searchInsert(B,k2)+i;
                if(B[al-i]==k2 && al+1 == ans2)
                    al++;
                cout <<"Position insert of ["<<k2<<"] is at " << al+1 << endl;
                i++;
            }
        }
        cout << "2nd term for median is : "<<k2<<endl;
        
        double ans = (k1+k2)/2;
        return ans;
    }
    
    return 0;
}

int main()
{
    //[ 1 2 3 4 5 ]
    //[ 3 4 5 6 7 8 ]
    //Answer = 4
    
    //A : [1 4 5]
    //B : [2 3]
    //Answer = 3
    
    //A : [ -50, -41, -40, -19, 5, 21, 28 ] 
    //B : [ -50, -21, -10 ]
    //Answer = -20
    
    //A : [ -37, 4, 7, 13, 29, 49, 50 ]
    //B : [ -24, -14, 32 ]
    //Answer = 10
    
    //A : [ -49, 33, 35, 42 ]
    //B : [ -26 ]
    //Answer = 33
    
    //A : [ -50, -34, -28, -23, 6, 18, 19, 30 ]
    //B : [ -28, -19, -17, -17, 4, 7, 23, 28, 39 ]
    //Answer = 4
    
    vector<int> A,B;
    
    A.push_back(-50);
    A.push_back(-34);
    A.push_back(-28);
    A.push_back(-23);
    A.push_back(6);
    A.push_back(18);
    A.push_back(19);
    A.push_back(30);
    
    B.push_back(-28);
    B.push_back(-19);
    B.push_back(-17);
    B.push_back(-17);
    B.push_back(4);
    B.push_back(7);
    B.push_back(23);
    B.push_back(28);
    B.push_back(39);

    printVec(A);
    printVec(B);
    cout << endl;
    
    double ans  = findMedianSortedArrays(A,B);
    cout <<endl<<"Answer is : "<< ans << endl;
    
}
