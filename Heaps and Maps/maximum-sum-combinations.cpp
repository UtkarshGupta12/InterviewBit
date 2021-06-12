#include <iostream>
#include <string>
#include<sstream>
#include <bits/stdc++.h>
#include <stack>
#include<cmath>
#include<iomanip>
#include <map>
#include <iterator>
#include <string.h>
#define M 1000000007
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

void printVecvec(vector<vector<int>> &vec)  
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
            cout << vec[i][j] << " ";
        cout << endl;        
    }}

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';}

void minshowpq(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, 
                                greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';}

//printHeap
    size_t IntegerLogarithm2(size_t arg) 
    {
      size_t logarithm = 0;
      while (arg >>= 1) ++logarithm;
      return logarithm;}   

    size_t IntegerPower2(size_t arg) 
    {
      if(arg)
        return (size_t)2 << (arg-1);
      else
        return 1;}   

    // returns total line length for the level
    size_t LineLength(size_t level, size_t item_width, size_t spaces_between) 
    {return IntegerPower2(level) * (item_width + spaces_between) - spaces_between;}   

    int printHeap(vector<int> &A)
    {
        std::vector<std::vector<int>> levels;

      // Height of the heap
      size_t levels_number = IntegerLogarithm2(A.size() + 1);
      levels.resize(levels_number);

      // Now fill the levels
      for (size_t i = 0; i < levels.size(); ++i) {
        size_t elements_number = IntegerPower2(i);
        levels[i].resize(elements_number);
        for (size_t j = elements_number - 1, p = 0; p < elements_number; ++j, ++p)
          levels[i][p] = A[j];
      }   

      if (levels_number < 1) return 0;

      int magnitude = (abs(A[0]) <= 1 ? 1 : abs(A[0]));
      size_t tab_width = (size_t)floor(log(double(magnitude)) / log(10.0)) + 1;
      // size_t longest_line = LineLength(levels_number - 1, tab_width, tab_width);
      std::vector<std::string> text;
      text.reserve(levels_number * 2 - 1); 

      // Do the aligned output to the strings array
      for (size_t i = 0; i < levels_number; ++i) {
        size_t outer_space_width = IntegerPower2(levels_number - 1 - i) - 1;
        size_t inner_space_width = outer_space_width * 2 + 1;
        std::string outer_space(outer_space_width * tab_width, ' ');
        std::string inner_space(inner_space_width * tab_width, ' ');

        std::ostringstream line;
        line << outer_space;

        if (i > 0) {
          std::ostringstream branchline;
          std::string joint(tab_width, '|');
          std::string branch(inner_space_width * tab_width, '-');

          branchline << outer_space;

          if (levels[i].size() > 0) {
            branchline << joint;
          }

          bool isline = true;
          for (size_t j = 1; j < levels[i].size(); ++j, isline = !isline) {
            if(isline)
              branchline << branch << joint;
            else
              branchline << inner_space << std::setfill(' ') <<
                  std::setw(tab_width) << joint;
          }

          branchline << outer_space;
          text.push_back(branchline.str());
        }

        if (levels[i].size() > 0) {
          line << std::setfill(' ') << std::setw(tab_width) << levels[i][0];
        }

        for (size_t j = 1; j < levels[i].size(); ++j) {
          line << inner_space << std::setfill(' ') <<
              std::setw(tab_width) << levels[i][j];
        }

        line << outer_space;
        text.push_back(line.str());
      }

      // Output the text
      for (auto& i : text)
        std::cout << i << std::endl;}

vector<int> solve(vector<int> &A, vector<int> &B, int K)
{
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());

    vector<int> res;
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> st;
    int count = 0;

    //Intialising pq and st
    pq.push(make_pair(A[0]+B[0],make_pair(0,0)));
    st.insert(make_pair(0,0));

    for(count = 0;count<K;count++)
    {
        res.push_back(pq.top().first);
        pq.pop();

        int i = pq.top().second.first;
        int j = pq.top().second.second;

        //i+1,j
        int sum = A[i+1]+B[j];
        if(st.find(make_pair(i+1,j))==st.end())
        {
            pq.push(make_pair(sum,make_pair(i+1,j)));
            st.insert(make_pair(i+1,j));}

        //i,j+1
        sum = A[i]+B[j+1];
        if(st.find(make_pair(i,j+1))==st.end())
        {
            pq.push(make_pair(sum,make_pair(i,j+1)));
            st.insert(make_pair(i,j+1));}    
    }

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
  vector<int> A = {4, 2, 5, 1}; 
  vector<int> B = {8, 0, 3, 5};
  int K = 3;   

  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  
  cout<<"A : ";printVec(A);
  cout<<"B : ";printVec(B);
  cout<<"No. of combinations : "<<K<<endl;

  vector<int> ans = solve(A,B,K);
  cout<<endl<<"Answer : ";printVec(ans);

  return 0;
}

/*
Input :  A[] : {3, 2} 
         B[] : {1, 4}
         K : 2 [Number of maximum sum
               combinations to be printed]
Output : 7    // (A : 3) + (B : 4)
         6    // (A : 2) + (B : 4)

Input :  A[] : {4, 2, 5, 1}
         B[] : {8, 0, 3, 5}
         K : 3
Output : 13   // (A : 5) + (B : 8)
         12   // (A : 4) + (B :  8)
         10   // (A : 2) + (B : 8)
*/

