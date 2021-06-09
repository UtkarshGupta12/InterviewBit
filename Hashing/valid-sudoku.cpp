#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
#define M 1000000007
using namespace std;
 
void printVec(vector<string> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " " << endl;
    }
    cout <<endl;}

void printMap(unordered_map<char,bool> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';}

int isValidSudoku(const vector<string> &A)
{
    int rows = A.size();
    int cols = A[0].size();
    unordered_map<char,bool> ump;

    //Checking each row
    cout<<"ROWS : "<<endl<<endl;
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            char c = A[i][j];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});
            //printMap(ump);            
        }
        ump.clear();}

    //Checking each cols
    cout<<"COLS : "<<endl<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});
            //printMap(ump);            
        }
        ump.clear();}

    //Checking each block of 3
    //BLOCK 1-1
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char c = A[i][j];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}

    ump.clear();
    //BLOCK 1-2       
    for(int i=3;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}

    ump.clear();
    //BLOCK 1-3       
    for(int i=6;i<9;i++)
    {
        for(int j=0;j<3;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}        

    ump.clear();
    //BLOCK 2-1        
    for(int i=0;i<3;i++)
    {
        for(int j=3;j<6;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}   
                
    ump.clear();
    //BLOCK 2-2        
    for(int i=3;i<6;i++)
    {
        for(int j=3;j<6;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}           

    ump.clear();
    //BLOCK 2-3        
    for(int i=6;i<9;i++)
    {
        for(int j=3;j<6;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}           

    ump.clear();
    //BLOCK 3-1        
    for(int i=0;i<3;i++)
    {
        for(int j=6;j<9;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}                   
    
    ump.clear();
    //BLOCK 3-2        
    for(int i=3;i<6;i++)
    {
        for(int j=6;j<9;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}                   

    ump.clear();
    //BLOCK 3-3        
    for(int i=6;i<9;i++)
    {
        for(int j=6;j<9;j++)
        {
            char c = A[j][i];
            if(c=='.') continue;
            if(ump.find(c)!=ump.end())
                return 0;
            else
                ump.insert({c,true});}}                   
    
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<string> A;
    A.push_back("....5..1.");
    A.push_back(".4.3.....");
    A.push_back(".....3..1");
    A.push_back("8......2.");
    A.push_back("..2.7....");
    A.push_back(".15......");
    A.push_back(".....2...");
    A.push_back(".2.9.....");
    A.push_back("..4......");

    printVec(A);

    int ans = isValidSudoku(A);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}
/*["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.
A : [ "....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......" ]
*/
