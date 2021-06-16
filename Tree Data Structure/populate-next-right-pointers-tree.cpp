/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root)
{
    TreeLinkNode* res = root;

    //BASE CASE
    if(root==NULL) return ;

    //Initialising Variables
    queue<TreeLinkNode*> q;
    vector<vector<TreeLinkNode*>> vec;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();
        vector<TreeLinkNode*> tmp;

        while(count--)
        {
            TreeLinkNode* temp = q.front();
            q.pop();

            if(temp->right!=NULL)
                q.push(temp->right);
            if(temp->left!=NULL)
                q.push(temp->left);

            tmp.push_back(temp);
        }

        reverse(tmp.begin(),tmp.end());
        vec.push_back(tmp);
    }

    //printTreeVecvec(vec);cout<<endl;
    //Connecting each right side
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size()-1;j++)
        {
            vec[i][j]->next = vec[i][j+1];
        }
        vec[i].back()->next = NULL;
    }

    return ;
}
