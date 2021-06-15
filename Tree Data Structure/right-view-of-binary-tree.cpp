/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root)
{
    //BASE CASE
    if(root==NULL) return {};

    //Initialising Variables
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();

        while(count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);

            if(count==0) res.push_back(temp->val);
        }
    }

    return res;
}
