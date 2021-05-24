#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &mat)  
{
    int nrows = mat.size();
    int ncols = mat[0].size();
    for(int i=0;i<nrows;i++)
    {
        for(int j=0;j<ncols;j++)
            cout << mat[i][j] << " ";
        cout << endl;        
    }        }

int maxArray(vector<vector<int> > &A)
{
    int nrows = A.size();
    int ncols = A[0].size();
    int max_array = INT_MIN;
    for(int i=0;i<nrows;i++)
        max_array = max(A[i][ncols-1],max_array);    
    
    return max_array;}

int searchInsert(vector<int> &A, int B) 
{
    int low = 0, high = A.size()-1;

    while(low <= high) 
    {
        int mid = (high + low) / 2;
        //cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;
        
        if(A[mid]==B)
        {
        	if(A[mid+1]==A[mid])
        	{
        		mid++;
        		return mid;	
        	}

        else 
        	return mid;     
        }
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
    return 0;}

int numberofElements(vector<vector<int>> &A,int K)
{
    int nrows = A.size();
    int ncols = A[0].size();
    int index=0;
    int count=0;

    for(int i=0;i<nrows;i++)
    {
        if(A[i][ncols-1]<=K)
        {
            index +=ncols;
            continue;
        }
        else
        {    
            count = searchInsert(A[i],K);
            index+=count;
        }    
    }
    return index;}    

int findMedian(vector<vector<int> > &A)
{
    int nrows = A.size();
    int ncols = A[0].size();
    int median = (nrows*ncols/2)+1;

    int min_array = A[0][0];
    int max_array = maxArray(A);
    cout <<"Minimum in the Array : "<<min_array<<endl;
    cout <<"Maximum in the Array : "<<max_array<<endl;
    int mid = -1;

    int low = min_array, high = max_array;
    int K = -1;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;
        K = numberofElements(A,mid);
        cout <<"Number of Elements less than "<<mid<<" : "<<K<<endl;

        if(high == mid && high == low)
            return mid;
            
        else if(median <= K)
            high = mid;
            
        else if(median>K)    
            low = mid+1;
        
        

    }
    return mid;
    
}


int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output3.txt","w",stdout);
#endif

	//  [1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3]
    vector<vector<int>> A(1);
    A[0].push_back(1);
    A[0].push_back(2);
    A[0].push_back(2);
    A[0].push_back(2);
    A[0].push_back(2);
    A[0].push_back(2);
    A[0].push_back(3);
    A[0].push_back(3);
    A[0].push_back(3);
    A[0].push_back(3);
    A[0].push_back(3);

    printMatrix(A);
    cout  << endl;

    int ans = findMedian(A);
    cout << endl << ans << endl;
}
