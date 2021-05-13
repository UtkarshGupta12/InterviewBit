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

int findMax(vector<vector<int>> &mat)
{
 
    // Initializing max element as INT_MIN
    int maxElement = INT_MIN;
 
    // checking each element of matrix
    // if it is greater than maxElement,
    // update maxElement
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] > maxElement) {
                maxElement = mat[i][j];
            }
        }
    }
 
    // finally return maxElement
    return maxElement;
}

int solve(vector<vector<int>> &A,int k)
{
    int N = A.size();
    int final_n = N - k + 1;
    int sum = 0,j=0;
    vector<vector<int>> mat1(N);
    for(int i=0;i<N;i++)
    {
        while(j<final_n)
        {
            for(int l=j;l<j+k;l++)
                sum+= A[i][l];
            
            mat1[i].push_back(sum);
            sum = 0;
            j++;
        }
        j=0;
    }  
    
    cout << endl;
    printMatrix(mat1);
    cout << endl;
    
    vector<vector<int>> mat2(final_n);
    for(int i=0;i<final_n;i++)
    {
        while(j<final_n)
        {
            for(int l=j;l<j+k;l++)
                sum+= mat1[l][i];
            
            mat2[i].push_back(sum);
            sum = 0;
            j++;
        }
        j=0;
    }  
    
    cout << endl;
    printMatrix(mat2);
    cout << endl;
    
    int max_sum = findMax(mat2);
    return max_sum;

}

int main()
{
    vector<vector<int>> A(4);
    A[0].push_back(1);
    A[0].push_back(2);
    A[0].push_back(-1);
    A[0].push_back(4);
    A[1].push_back(-8);
    A[1].push_back(-3);
    A[1].push_back(4);
    A[1].push_back(2);
    A[2].push_back(3);
    A[2].push_back(8);
    A[2].push_back(10);
    A[2].push_back(-8);
    A[3].push_back(-4);
    A[3].push_back(-1);
    A[3].push_back(1);
    A[3].push_back(7);
    
    printMatrix(A); 
    
    int N = solve(A,3);
    
    cout << N << endl;
    
}
