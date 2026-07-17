/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootleaf(TreeNode* root, int node, vector<TreeNode*>& path){
        if(!root) return false;
        path.push_back(root);
        if(root->val == node){
            return true;
        }

        if(rootleaf(root->left, node, path) || rootleaf(root->right, node, path)){
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;

        rootleaf(root, p->val, pathp);
        rootleaf(root, q->val, pathq);

        int n = min(pathp.size(), pathq.size());
        TreeNode* ans = root;
        for(int i=0;i<n;i++){
            if(pathp[i]->val==pathq[i]->val){
                ans = pathp[i];
            }else{
                break;
            }
        }
        return ans;
    }
};