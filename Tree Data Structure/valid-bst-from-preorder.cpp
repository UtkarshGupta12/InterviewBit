int solve(TreeNode* root1)
{
    vector<int> vec = {8,3,1,6,4,7,10,14,13};
    stack<int> st;
    int root = INT_MIN;

    for(int i=0;i<vec.size();i++)
    {
        while(!st.empty() && vec[i]>st.top())
        {
            root = st.top();
            st.pop();
        }

        if(vec[i]<root)
            return 0;

        st.push(vec[i]);
        PrintStack(st);cout<<endl;
    }

    return 1;
}
