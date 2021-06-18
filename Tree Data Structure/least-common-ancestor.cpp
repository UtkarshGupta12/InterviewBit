/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPath(TreeNode* curr_node,int p,queue<int> s,queue<int> &a)
{
    if(curr_node==NULL) return;

    s.push(curr_node->val);
    if(curr_node->val==p)
    {
        a = s;
        return;    
    }

    findPath(curr_node->left,p,s,a);
    findPath(curr_node->right,p,s,a);
}

int Solution::lca(TreeNode* root,int p,int q)
{
    if(root==NULL) return -1;

    queue<int> sp,sq,temp;

    findPath(root,p,temp,sp);
    findPath(root,q,temp,sq);

    //cout<<"P -> ";printQueue(sp);cout<<endl;
    //cout<<"Q -> ";printQueue(sq);cout<<endl;

    //Finding Answer
    int ans = -1;
    while(!sp.empty() && !sq.empty())
    {
        if(sp.front()==sq.front())
        {
            ans = sp.front();
            sq.pop();
            sp.pop();
        }
        else
            break;
    }

    return ans;
}
