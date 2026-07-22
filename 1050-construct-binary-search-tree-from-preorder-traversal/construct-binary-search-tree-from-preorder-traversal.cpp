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
    TreeNode* build(vector<int>& preorder, int upper, int& i){
        if(i>=preorder.size() || preorder[i] > upper) return nullptr;

        TreeNode* temp = new TreeNode(preorder[i]);
        i++;

        temp->left = build(preorder, temp->val, i);
        temp->right = build(preorder, upper, i);

        return temp;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, INT_MAX, i);
    }
};