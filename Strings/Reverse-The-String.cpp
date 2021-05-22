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

void removeSpaces(string &str)
{
    // n is length of the original string
    int n = str.length();
 
    // i points to next position to be filled in
    // output string/ j points to next character
    // in the original string
    int i = 0, j = -1;
 
    // flag that sets to true is space is found
    bool spaceFound = false;
 
    // Handles leading spaces
    while (++j < n && str[j] == ' ');
 
    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[j] == '.' || str[j] == ',' ||
                 str[j] == '?') && i - 1 >= 0 &&
                 str[i - 1] == ' ')
                str[i - 1] = str[j++];
 
            else
                // copy current character at index i
                // and increment both i and j
                str[i++] = str[j++];
 
            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }
 
    // Remove trailing spaces
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
}

void reverseWords(string &A)
{
    if(A.size()==1)
        break;
        
    reverse(A.begin(),A.end());
    cout << A << endl;
    
    A.insert(0," ");
    
    vector<int> spaces;
    spaces.push_back(-1);
    
    for(int i=0;i<A.size()-1;i++)
        if(A[i]==' ')
            spaces.push_back(i);
            
    spaces.push_back(A.size());       
    printVec(spaces);        
    
    for(int i=0;i<spaces.size();i++)
    {
        cout <<"From : "<<spaces[i]+1<<" to "<<spaces[i+1]<<endl;
        reverse(A.begin()+spaces[i]+1,A.begin()+spaces[i+1]);
        cout  << A << endl;
    }
    
    char c = A.back();
    cout << c << endl;
    removeSpaces(A);
    A.insert(A.end(),c);
    cout  << A << endl; 
}

int main()
{
    //fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq
    string ques = "j";
    cout << "Ques : "<< ques << endl<<endl;
    reverseWords(ques);
    cout << "Ans  : "<< ques << endl;
    
    
    //iwfcqq igjgip myq sn dqmy qfho sswz ouhsuhf kxorifrhubk jsx ulc osdt fwbpudnbrozzifml
    //iwfcqq igjgip myq sn dqmy qfho sswz ouhsuhf kxorifrhubk jsx ulc osdt fwbpudnbrozzifml

}
