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
        queue<vector<TreeNode*>> q;
        vector<TreeNode*> temp;
        temp.push_back(root);
        q.push(temp);
        int level = 1;
        int maxi = INT_MIN;
        int maxl = 1;
        while(!q.empty()){
            vector<TreeNode*> vtemp = q.front();
            q.pop();
            vector<TreeNode*> next;
            int stemp = 0;
            for(auto i : vtemp){
                stemp += i->val;
                if(i->left!=nullptr){
                    next.push_back(i->left);
                }
                if(i->right!=nullptr){
                    next.push_back(i->right);
                }
            }
            if(stemp>maxi){
                maxl = level;
                maxi = stemp;
            }
            if(!next.empty()){
                q.push(next);
            }
            level++;
        }
        return maxl;
    }
};