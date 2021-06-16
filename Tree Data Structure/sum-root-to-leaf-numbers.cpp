/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long long unsigned convert2Number(vector<int> vec)
{
    long long unsigned num=0;

    for(int i=0;i<vec.size();i++)
    {
        num = num*10;
        num += vec[i];
        num = num%1003;
    }
    
    //cout<<"Sum : "<<num<<endl;
    return num;}

void getallPaths(TreeNode* curr_node,vector<vector<int>> &vec,
                        vector<int> path)
{
    if(curr_node==NULL) return;

    //PREORDER
    path.push_back(curr_node->val);
    if(curr_node->left==NULL && curr_node->right==NULL)
        vec.push_back(path);

    getallPaths(curr_node->left, vec, path);
    getallPaths(curr_node->right, vec, path);
}

int Solution::sumNumbers(TreeNode* root)
{
    if(root==NULL) return 0;
    
    vector<vector<int>> res;
    getallPaths(root,res,{});

    //Adding two numbers
    long long unsigned sum = 0;
    
    for(int i=0;i<res.size();i++)
    {
        sum += convert2Number(res[i]);
        //cout<<"Sum : "<<sum<<endl;
    }        
    
    return (int)sum%1003;
} 
