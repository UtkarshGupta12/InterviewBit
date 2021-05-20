// Code to make binary from string
string bin(long n)
{
    string binary = "";
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        binary+="1";
      }
      else
      {
        binary+="0";
      }
    }
    return binary;
}

int main() 
{
    unsigned int A = 12325;
    
    cout << "A : "<<A<<endl;
    cout <<"Answer : "<<numSetBits(A) << endl;
    
    return 0;
}
