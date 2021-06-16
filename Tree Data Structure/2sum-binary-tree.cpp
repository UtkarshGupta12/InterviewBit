/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getATree(TreeNode* curr_node,unordered_map<int,int> &ump,
                            bool &found, int k)
{
    if(curr_node==NULL) return;

    int num = curr_node->val;
    if(ump.find(k-num)!=ump.end())
    {
        found = true;
        return;}
    else
        ump.insert(make_pair(num,0));    

    getATree(curr_node->left,ump,found,k);
    getATree(curr_node->right,ump,found,k);
}

int Solution::t2Sum(TreeNode* root, int k)
{
    if(root==NULL) return 0;

    unordered_map<int,int> ump;
    bool found = false;
    getATree(root,ump,found,k);

    return found;
}
