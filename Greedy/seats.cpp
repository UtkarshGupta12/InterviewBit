//Failing for larger test cases

double findMedian(vector<int> a)
{
    int n = a.size();
  
    // If size of the arr[] is even
    if (n % 2 == 0) {
  
        // Applying nth_element
        // on n/2th index
        nth_element(a.begin(),a.begin() + n / 2,a.end());
  
        // Applying nth_element
        // on (n-1)/2 th index
        nth_element(a.begin(),a.begin() + (n - 1) / 2,a.end());
  
        // Find the average of value at
        // index N/2 and (N-1)/2
        return (double)(a[(n - 1) / 2]+ a[n / 2])/ 2.0;
    }
  
    // If size of the arr[] is odd
    else {
  
        // Applying nth_element
        // on n/2
        nth_element(a.begin(),a.begin() + n / 2,a.end());
  
        // Value at index (N/2)th
        // is the median
        return (double)a[n / 2];
    }}

int minjumps(vector<int> &vec,int N)
{
    int count = vec.size();
    int sum = 0;
    for(int i=0;i<count;i++)
       sum += N-vec[i];    

    int ans = sum - count*(count-1)/2;
    return ans;    }

int Solution::seats(string A) 
{
    int res = 0;

    //First Find the Median 
    vector<int> xs;
    for(int i=0;i<A.size();i++)
        if(A[i]=='x') xs.push_back(i+1);
        
    if(xs.size()==0) return 0;
            
    double median_index =  findMedian(xs);
    //cout<<"Position of X's : ";printVec(xs);cout<<"Medain : "<<median_index<<endl;

    //X's on the Left of Median 
    int left = 0;
    for(int i=0;i<xs.size();i++)
    {
        if((double)xs[i]<median_index) left++;
        else break;}
    //cout<<"X's on the left of median  : "<<left<<endl;

    //X's on the Left of Median 
    int right = xs.size()-left;
    //cout<<"X's on the right of median : "<<right<<endl;

    //Counting all jumps from left
    string left_side = A.substr(0,(int)median_index);
    for(int i=0;i<left_side.size();i++)
    {
        if(left_side[i]=='.') 
        {    
            left_side.erase(left_side.begin()+i);
            i--;
        }    
        else
            break;}
    //cout<<"Left Side  : "<<left_side<<endl;  
    xs.clear();
    for(int  i=0;i<left_side.size();i++)
        if(left_side[i]=='x') xs.push_back(i+1);  
    //(6-1) + (6-3) + (6-6) - 2*(3/2) = 5
    res += minjumps(xs,left_side.size());

    //Counting all jumps from right
    string right_side = A.substr((int)median_index,A.size()-(int)median_index);
    reverse(right_side.begin(),right_side.end());
    for(int i=0;i<right_side.size();i++)
    {
        if(right_side[i]=='.') 
        {    
            right_side.erase(right_side.begin()+i);
            i--;
        }    
        else
            break;}
    //cout<<"Right Side : "<<right_side<<endl;
    xs.clear();
    for(int i=0;i<right_side.size();i++)
        if(right_side[i]=='x') xs.push_back(i+1);
    res += minjumps(xs,right_side.size());

    return res%10000003;
}
