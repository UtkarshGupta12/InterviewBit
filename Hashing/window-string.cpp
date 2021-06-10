//Completed with TLE

bool checkWindow(unordered_map<char,int> window,unordered_map<char,int> small)
{
    if(window.size()<small.size()) return false;

    for(auto it=small.begin(); it!=small.end(); it++)
    {
        if(window.find(it->first)==window.end())
            return false;
        else 
        {
            if(window[it->first]<it->second)
                return false;
        }
    }
    return true;}

string Solution::minWindow(string S, string T) 
{
    int lenT = T.size();
    int lenS = S.size();
    
    if(lenS==0||lenT==0) return "";
    else if(lenT>lenS) return "";
    else if(lenT==1) {
        for(int i=0;i<lenS;i++)
        if(S[i]==T[0]) return T;}
    else if(lenS==1) {
        if (S.find(T[0]) != std::string::npos) return T;}
    
    int min_len = INT_MAX;
    int pos = 0;
    char c;
    int len;

    string res = "";
    unordered_map<char,int> small;
    unordered_map<char,int> window;

    //Creating map of answers
    for(int i=0;i<T.size();i++)
        small[T[i]]++;
    //printMap(small);

    //Creating a sliding window
    deque<char> dq;

    //Creating a minimum window
    for(int i=0;i<lenT;i++)
        dq.push_back(S[i]);
    //showdq(dq);

    //Storing elements into minimum window
    for(int i=0;i<lenT;i++)
        window[S[i]]++;
    //printMap(window);

    //Iterating a sliding window
    for(int i=lenT;i<lenS;i++)
    {
        dq.push_back(S[i]);
        window[S[i]]++;

        if(checkWindow(window,small))
        {
            //min_len = min(dq.size(),min_len);
            while(checkWindow(window,small))
            {
                c = dq.front();
                window[dq.front()]--;
                dq.pop_front();
            }
            dq.push_front(c);
            window[c]++;
            //cout<<"i -> "<<i<<" | ";
            //showdq(dq);
            int temp = min_len;
            len = dq.size();
            min_len = min(min_len,len);
            
            if(len==min_len && temp!=min_len)
            {
                pos = i-len+1;
                //cout<<"pos -> "<<pos
                //<<" & len -> "<<min_len<<endl;
                //showdq(dq);
            }    
        }        } 

    while(checkWindow(window,small))
    {
        c = dq.back();
        window[dq.back()]--;
        dq.pop_back();}

    dq.push_back(c);
    window[c]++;

    len = dq.size();
    min_len = min(min_len,len);
    //showdq(dq);

    //cout<<"pos -> "<<pos<<" & len -> "<<min_len<<endl;
    //showdq(dq);    

    if(pos==0 && min_len==S.size()+1) return "";

    for(int i=pos;i<pos+min_len;i++)
        res+=S[i];

    return res;
}

