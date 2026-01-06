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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int maxl = 1;
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            int stemp = 0;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                stemp+=curr->val;
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            if(stemp>maxi){
                maxi = stemp;
                maxl = level;
            }
            level++;
        }
        return maxl;
    }
};