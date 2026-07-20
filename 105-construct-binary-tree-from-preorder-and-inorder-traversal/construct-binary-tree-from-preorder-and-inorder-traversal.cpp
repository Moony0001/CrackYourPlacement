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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder ,int preL, int preR, int inL, int inR){
        if(preL>preR && inL>inR) return nullptr;
        int f = preorder[preL];
        TreeNode* root = new TreeNode(f);
        int k = -1;
        for(int i=inL;i<=inR;i++){
            if(inorder[i] == f){
                k = i;
                break;
            }
        }

        int left = k-inL;

        root->left = build(preorder, inorder, preL+1, preL+left, inL, k-1);
        root->right = build(preorder, inorder, preL+left+1, preR, k+1, inR);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};