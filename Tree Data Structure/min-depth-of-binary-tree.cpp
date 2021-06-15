/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root)
{
    //BASE CASE
    if(root==NULL) return 0;

    //Preparing for Level Order Traversal
    int level = 0;
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

            if(temp->right==NULL && temp->left==NULL)
                return ++level;
        }

        level++;
    }

    return level;
}
