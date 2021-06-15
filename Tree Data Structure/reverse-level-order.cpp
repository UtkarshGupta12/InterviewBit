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
    vector<int> res;

    //BASE CASE
    if(root==NULL) return res;

    //Travelling Through Each Level
    queue<TreeNode*> q;
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

            res.push_back(temp->val);
        }
    }

    reverse(res.begin(),res.end());
    return res;
}
