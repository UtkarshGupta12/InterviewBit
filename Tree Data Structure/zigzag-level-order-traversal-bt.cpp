/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if(root==NULL) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        vector<int> vec;
        int count = q.size();
        vec = {};

        while(count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->right!=NULL)
                q.push(temp->right);
            if(temp->left!=NULL)
                q.push(temp->left);

            vec.push_back(temp->val);
        }
        res.push_back(vec);
    }

    //Inverting Odd Places
    for(int i=0;i<res.size();i++)
    {
        if(i%2==0)
            reverse(res[i].begin(),res[i].end());
    }

    return res;
}
