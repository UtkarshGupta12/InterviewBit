/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> path;

void pushall(TreeNode* root)
{
    while(root)
    {
        path.push(root);
        root = root->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) 
{
    pushall(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    if(!path.empty()) return true;
    else return false;
    
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    TreeNode* ans = path.top();
    path.pop();
    
    if(ans->right) pushall(ans->right);
    
    return ans->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
