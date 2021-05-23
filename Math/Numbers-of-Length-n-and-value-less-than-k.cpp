#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &A, int B){
    int low = 0, high = A.size()-1;

    while(low <= high) {#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &A, int B){
    int low = 0, high = A.size()-1;

    while(low <= high) {
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

void printVec(vector<int> &v){
    int N = v.size();
    for(int i=0;i<N;i++){
        cout << v[i] << " ";
    }
    cout <<endl;
}

int multiplyTerms(vector<int> &vec,int index,int times){
    int N = vec.size(),ans=1;
    int zeroesinA = count(vec.begin(),vec.end(),0);
    
    ans = N-zeroesinA-index;
    for(int i=1;i<times;i++){
        ans = ans*N;
    }
    return ans;
}

int PermutationsfromStarting(vector<int> &A,int index, int B){
    int zeroesinA = count(A.begin(),A.end(),0);
    int ans = index - zeroesinA ;
    
    for(int i=1;i<B;i++){
        ans = ans*A.size();
    }
    return ans;    
}

int PermutationsfromMiddle(vector<int> &A,int index, int B){
    int ans = index ;
    
    for(int i=1;i<B;i++){
        ans = ans*A.size();
    }
    return ans;    
}

vector<int> int2vec(int N){
    vector<int> num;
    
    if(N==0)
        num.push_back(0);
        
    while(N){
        num.push_back(N%10);
        N=N/10;
    }
    reverse(num.begin(),num.end());
    return num;
}

int solve(vector<int> &A, int B, int C){
    
    if(A.size()==0)
        return 0;
    else if(A.back()==0 && B == 1)
        return 1;
        
    vector<int> c,permutation(B);
    c = int2vec(C);
    int B_permanent = B;
    cout <<"c : ";
    printVec(c);
    
    int digits = c.size(),ans;
    int zeroesinA = count(A.begin(),A.end(),0);
    cout << "Zeroes in A : "<<zeroesinA<<endl;
    int A_max = 0;
    for(int i=0;i<B;i++){
        A_max += A.back();
        A_max *= 10;
    }
    A_max/=10;
    cout<<"A_max : "<<A_max<<endl;
    
    //CASE 1 - (B>digits)
    if(B>digits){
        return 0;
    }
    
    //CASE 2 - (B<digits)
    if(B<digits || C > A_max){
        ans = multiplyTerms(A,0,B);
        if(B==1&&zeroesinA>0)
        ans+=zeroesinA;
        return ans;
    }
    
    //CASE 3 - (B==digits)

    if(B==1&&c.size()==1)
    	return searchInsert(A,c[0]);

    int firstPermutation = searchInsert(A,c[0]);
    cout <<endl<< "firstPermutation : "<<firstPermutation<<endl;
    ans = PermutationsfromStarting(A,firstPermutation,B);
    cout << "Part I of Permutations : "<<ans<<endl<<endl;
    int temp = ans;
    
    if(ans!=0){
        for(int i=1;i<2;i++){
        firstPermutation = searchInsert(A,c[i]);
        B--;
        ans += PermutationsfromMiddle(A,firstPermutation,B);
        cout <<"Progressing with Answer : "<< ans << endl;
        if(ans == temp)
            break;
    }
    }
    
    if(B_permanent==1&&zeroesinA>0)
        ans+=zeroesinA;
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt 	
	freopen("input1.txt","r",stdin);
	// for writing output to output.txt
	freopen("output1.txt","w",stdout);
#endif

	vector<int> A;
    A.push_back(0);
    A.push_back(1);
    //A.push_back(2);
    //A.push_back(3);
    //A.push_back(4);
    A.push_back(5);
    //A.push_back(6);
    //A.push_back(7);
    //A.push_back(8);
    //A.push_back(9);
    
    cout <<"Set of digits are (A) : ";
    printVec(A);
    
    int B = 1;
    cout <<"Length of answer (B) : "<<B<<endl;
    
    int C = 2;
    cout <<"All values should be less than (C) : "<<C<<endl<<endl;
    
    int ans = solve(A,B,C);
    cout <<endl<< "Ans  : "<< ans << endl;

    //int n;
    //cin >> n;
    //cout << n;	

}


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

void printVec(vector<int> &v){
    int N = v.size();
    for(int i=0;i<N;i++){
        cout << v[i] << " ";
    }
    cout <<endl;
}

int multiplyTerms(vector<int> &vec,int index,int times){
    int N = vec.size(),ans=1;
    int zeroesinA = count(vec.begin(),vec.end(),0);
    
    ans = N-zeroesinA-index;
    for(int i=1;i<times;i++){
        ans = ans*N;
    }
    return ans;
}

int PermutationsfromStarting(vector<int> &A,int index, int B){
    int zeroesinA = count(A.begin(),A.end(),0);
    int ans = index - zeroesinA ;
    
    for(int i=1;i<B;i++){
        ans = ans*A.size();
    }
    return ans;
    
}

int PermutationsfromMiddle(vector<int> &A,int index, int B){
    int ans = index ;
    
    for(int i=1;i<B;i++){
        ans = ans*A.size();
    }
    return ans;
    
}

vector<int> int2vec(int N){
    vector<int> num;
    
    if(N==0)
        num.push_back(0);
        
    while(N){
        num.push_back(N%10);
        N=N/10;
    }
    reverse(num.begin(),num.end());
    return num;
}

int solve(vector<int> &A, int B, int C){
    
    if(A.size()==0)
        return 0;
    else if(A.back()==0 && B == 1)
        return 1;
        
    vector<int> c,permutation(B);
    c = int2vec(C);
    cout <<"c : ";
    printVec(c);
    
    int digits = c.size(),ans;
    int zeroesinA = count(A.begin(),A.end(),0);
    cout << "Zeroes in A : "<<zeroesinA<<endl;
    int A_max = 0;
    for(int i=0;i<B;i++){
        A_max += A.back();
        A_max *= 10;
    }
    A_max/=10;
    cout<<"A_max : "<<A_max<<endl;
    
    //CASE 1 - (B>digits)
    if(B>digits){
        return 0;
    }
    
    //CASE 2 - (B<digits)
    if(B<digits || C > A_max){
        ans = multiplyTerms(A,0,B);
        if(B==1&&zeroesinA>0)
        ans+=zeroesinA;
        return ans;
    }
    
    //CASE 3 - (B==digits)
    int firstPermutation = searchInsert(A,c[0]);
    cout <<endl<< "firstPermutation : "<<firstPermutation<<endl;
    ans = PermutationsfromStarting(A,firstPermutation,B);
    cout << "Part I of Permutations : "<<ans<<endl<<endl;
    
    if(ans!=0){
        for(int i=1;i<B;i++){
        firstPermutation = searchInsert(A,c[i]);
        B--;
        ans += PermutationsfromMiddle(A,firstPermutation,B);
        cout <<"Progressing with Answer : "<< ans << endl;
    }
    }
    
    if(B==1&&zeroesinA>0)
        ans+=zeroesinA;
    
    return ans;
}

int main(){
    vector<int> A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(9);
    
    cout <<"Set of digits are (A) : ";
    printVec(A);
    
    int B = 5;
    cout <<"Length of answer (B) : "<<B<<endl;
    
    int C = 42950;
    cout <<"All values should be less than (C) : "<<C<<endl<<endl;
    
    int ans = solve(A,B,C);
    cout <<endl<< "Ans  : "<< ans << endl;
    
}
