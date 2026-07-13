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
        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* last = nullptr;

        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* peek = st.top();

                if(peek->right != nullptr && last != peek->right){
                    curr = peek->right;
                }else{
                    ans.push_back(peek->val);
                    last = st.top();
                    st.pop();
                }
            }
        }

        return ans;
    }
};