/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode * build_BST(TreeNode *root,int a)
    {
        if(root==NULL)
        { 
            TreeNode * temp=new TreeNode(a);
            return temp;
        }
        if(a<root->val)
            root->left=build_BST(root->left,a);
        else 
            root->right=build_BST(root->right,a);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& v) {
        TreeNode *root=new TreeNode(v[0]);
        for(int i=1;i<v.size();i++)
        {
           TreeNode *temp = build_BST(root,v[i]);
        }
        return root;
    }
};
