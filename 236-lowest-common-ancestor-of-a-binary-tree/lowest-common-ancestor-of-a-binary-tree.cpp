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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!mp.count(p) || !mp.count(q)){
            TreeNode* curr = nodes.front();
            nodes.pop();

            if(curr->left){
                mp[curr->left] = curr;
                nodes.push(curr->left);
            }

            if(curr->right){
                mp[curr->right] = curr;
                nodes.push(curr->right);
            }
        }

        unordered_set<TreeNode*> ancestors;
        while(p!=nullptr){
            ancestors.insert(p);
            p = mp[p];
        }

        while(!ancestors.count(q)){
            q = mp[q];
        }

        return q;
    }
};