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
    bool binfin(TreeNode* root, int key, TreeNode* look){
        if(!root) return false;

        if(key > root->val){
            return  binfin(root->right, key, look);
        }else if(key < root->val){
            return binfin(root->left, key, look);
        }
        return look!=root ? true : false;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            int n = st.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = st.top();
                st.pop();
                int val = k-curr->val;
                if(binfin(root, val, curr)){
                    return true;
                }
                if(curr->left){
                    st.push(curr->left);
                }
                if(curr->right){
                    st.push(curr->right);
                }
            }
        }
        return false;
    }
};