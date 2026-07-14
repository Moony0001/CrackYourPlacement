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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;

        int flag = 0;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            if(flag){
                stack<int> st;
                for(int i=0;i<n;i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    st.push(curr->val);
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }

                while(!st.empty()){
                    temp.push_back(st.top());
                    st.pop();
                }
            }else{
                for(int i=0;i<n;i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    temp.push_back(curr->val);
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};