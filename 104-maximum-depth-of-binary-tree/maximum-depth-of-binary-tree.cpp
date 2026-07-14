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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root,1});
        TreeNode* curr = root;
        int ans = 0;
        int temp = 0;
        while(!st.empty()){
            auto curr = st.top();
            st.pop();

            ans = max(ans, curr.second);
            if(curr.first->left){
                st.push({curr.first->left, curr.second+1});
            }
            if(curr.first->right){
                st.push({curr.first->right, curr.second+1});
            }
        }
        return ans;
    }
};