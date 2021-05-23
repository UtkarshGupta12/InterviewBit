// TLE
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

void merge(vector<int> &A, vector<int> &B)
{
	int n = A.size();
	int m = B.size();
	int a=0,b=0;

	while(A.size()!=n+m){
		if(A[a]>=B[b]){
			A.insert(A.begin()+a,B[b]);
			b++;
		}
		
		else 
			a++;
		
		printVec(A);
	}
	
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt 	
	freopen("input1.txt","r",stdin);
	// for writing output to output.txt
	freopen("output1.txt","w",stdout);
#endif

	vector<int> A;
	vector<int> B;

	A.push_back(-5);
	//A.push_back(2);

	B.push_back(-5);
	//B.push_back(2);
	//B.push_back(7);
	//B.push_back(7);

	cout << "A : ";
	printVec(A);
	cout << "B : ";
	printVec(B);

	merge(A,B);

	cout << endl << "Result : ";
	printVec(A);

}

