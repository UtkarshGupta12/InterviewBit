/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B)
{
    if(A==NULL && B==NULL) return true;
    if(A->val != B->val) return false;

    queue<TreeNode*> qa;
    queue<TreeNode*> qb;

    qa.push(A);
    qb.push(B);

    while(!qa.empty() && !qb.empty())
    {
        int countA = qa.size();
        int countB = qb.size();

        while(countA && countB && countA==countB)
        {
            TreeNode* tempA = qa.front();
            TreeNode* tempB = qb.front();
            qa.pop();qb.pop();

            if(tempA->right!=NULL)
                qa.push(tempA->right);
            if(tempA->left!=NULL)
                qa.push(tempA->left);
            if(tempB->right!=NULL)
                qb.push(tempB->right);
            if(tempB->left!=NULL)
                qb.push(tempB->left);

            if(tempA->val != tempB->val)
                return false;

            countA--;
            countB--;
        }
    }
    
    if(!qa.empty()||!qb.empty()) return false;

    return true;
}
