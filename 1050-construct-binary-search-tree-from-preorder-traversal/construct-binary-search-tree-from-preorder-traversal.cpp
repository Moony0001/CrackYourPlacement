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
    TreeNode* bstmaker(vector<int>& inorder, vector<int>& preorder, int preL, int preR, int inL, int inR){
        if(preL > preR || inL > inR) return nullptr;
        int f = preorder[preL];
        TreeNode* root = new TreeNode(f);
        int k = -1;
        for(int i=inL;i<=inR;i++){
            if(inorder[i]==f){
                k = i;
                break;
            }
        }

        int left = k-inL;

        root->left = bstmaker(inorder, preorder, preL+1, preL+left, inL, k-1);
        root->right = bstmaker(inorder, preorder, preL+left+1, preR, k+1, inR);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        return bstmaker(inorder, preorder, 0, n-1, 0, n-1);
    }
};