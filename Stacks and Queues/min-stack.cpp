stack<int> st;
stack<int> mn;

MinStack::MinStack() 
{
    while(!st.empty()) st.pop();
    while(!mn.empty()) mn.pop();
}

void MinStack::push(int x) 
{
    st.push(x);
    if(mn.empty() || mn.top()>x) mn.push(x);
}

void MinStack::pop() 
{
    if(st.empty()) return ;
    if(st.top()==mn.top()) mn.pop();
    
    st.pop();
}

int MinStack::top() 
{
    if(st.empty()) return -1;
    else return st.top();
}

int MinStack::getMin() 
{
    if(mn.empty()) return -1;
    else return mn.top();
}

