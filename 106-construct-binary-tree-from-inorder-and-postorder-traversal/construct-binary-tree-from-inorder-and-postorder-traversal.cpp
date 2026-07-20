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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int postL, int postR, int inL, int inR){
        if(inL > inR || postL>postR) return nullptr;
        int f = postorder[postR];
        TreeNode* root = new TreeNode(f);
        int k = 0;
        for(int i=inL;i<=inR;i++){
            if(inorder[i]==f){
                k = i;
                break;
            }
        }

        int left = k - inL;

        root->left = build(inorder, postorder, postL, postL+left-1, inL, k-1);
        root->right = build(inorder, postorder, postL+left, postR-1, k+1, inR);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n-1, 0, n-1);
    }
};