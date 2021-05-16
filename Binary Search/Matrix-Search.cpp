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

void printMatrix(vector<vector<int>> &mat)  
{
    int nrows = mat.size();
    int ncols = mat[0].size();
    for(int i=0;i<nrows;i++)
    {
        for(int j=0;j<ncols;j++)
            cout << mat[i][j] << " ";
        cout << endl;        
    }        
}

int FindMinRow(vector<vector<int>> &A,int target)
{
   int nrows = A.size();
   int ncols = A[0].size(); 
   int low = 0,high = nrows-1;
   while(low<=high)
   {
        int mid = (low+high)/2;
        if(A[mid][0] <= target && mid < high && A[mid+1][0] > target ) 
            return mid; 
        else if(A[mid][0] <= target && mid < high && A[mid+1][0] == target ) 
            return mid+1;
        else if(A[mid][0] <= target && mid == high) 
            return mid;    
        else if(A[mid][0] < target && A[mid+1][0] < target) 
            low = mid + 1;
        else
            high = mid - 1;
   }
   return 0;
}

bool binarySearch(vector<vector<int>> &A, int target, int row_num) 
{
    int nrows = A.size();
    int ncols = A[0].size(); 
	int start = 0, ending = ncols-1;
	while(start <= ending) 
	{
		int mid = (start + ending) / 2;
		if(A[row_num][mid] == target) 
			return true; 
		else if(A[row_num][mid] < target) 
			start = mid + 1;
		else 
			ending = mid - 1;
		
	}
	return false;
}

bool searchMatrix(vector<vector<int>> &A, int target)
{
    int nrows = A.size();
    int ncols = A[0].size();
    int row_num = FindMinRow(A,target);
    cout << row_num << endl;
    return binarySearch(A,target,row_num);
}

int main()
{

  //[1]
  //[11]
  //[49]
  //[74]
  //[77]
  //[78]
  //[93]
  //[94]

    vector<vector<int>> A(8);
    A[0].push_back(1);
    A[1].push_back(11);
    A[2].push_back(49);
    A[3].push_back(74);
    A[4].push_back(77);
    A[5].push_back(78);
    A[6].push_back(93);
    A[7].push_back(94);


    printMatrix(A);
    
    cout << searchMatrix(A,49) << endl;
    
    //cout<< sol << endl; 
}
