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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode*> st;
        stack<int> rev;

        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            rev.push(curr->val);
            st.pop();
            if(curr->left!=nullptr){
                st.push(curr->left);
            }
            if(curr->right!=nullptr){
                st.push(curr->right);
            }
        }

        while(!rev.empty()){
            ans.push_back(rev.top());
            rev.pop();
        }
        return ans;
    }
};