/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int x)
{
    //BASE CASE
    if(root==NULL || root->val == x) return {};
    
    //Traversing through level
    queue<TreeNode*> q;
    vector<int> cousins;
    int sibling = INT_MIN;
    bool thisisit = false;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();

        while(count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->right!=NULL)
                q.push(temp->right);
            if(temp->left!=NULL)
                q.push(temp->left);

            cousins.push_back(temp->val);

            if(temp->val==x) thisisit = true;

            if(temp->right && temp->right->val==x)
            {
                if(temp->left) 
                    sibling = temp->left->val;
            }
            else if(temp->left && temp->left->val==x)
            {
                if(temp->right) 
                    sibling = temp->right->val;
            }

        }

        if(thisisit) break;
        else cousins = {};
    }

    //Deleting Sibling and X
    for(int i=0;i<cousins.size();i++)
    {
        if(cousins[i] == x || cousins[i] == sibling)
        {
            cousins.erase(cousins.begin()+i);
            i--;
        }}
    //reverse(cousins.begin(),cousins.end());    

    return cousins;
}
