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
    struct info{
        bool isbst;
        int mini;
        int maxi;
        int subsum;
    };
    
    int maxsum;

    info trav(TreeNode* root){
        if(!root) return {true, INT_MAX, INT_MIN, 0};

        info left = trav(root->left);
        info right = trav(root->right);
        info rans ;
        if(left.isbst && right.isbst){
            int temp = root->val;
            if(temp > left.maxi && temp < right.mini){
                rans.isbst = true;
                rans.subsum = temp + left.subsum + right.subsum;
                maxsum = max(maxsum, rans.subsum);
                rans.mini = min(temp,left.mini);
                rans.maxi = max(temp,right.maxi);
            }else{
                rans.isbst = false;
            }
        }
        return rans;
    }


    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        trav(root);
        return maxsum;
    }
};