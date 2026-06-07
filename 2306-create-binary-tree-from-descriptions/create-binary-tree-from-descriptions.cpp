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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,pair<TreeNode*,int>> mp;
        TreeNode* root = new TreeNode(descriptions[0][0]);
        mp[descriptions[0][0]] = {root, 0};
        for(int i=0;i<n;i++){
            TreeNode* parent;
            TreeNode* child;
            if(!mp.count(descriptions[i][0])){
                parent = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = {parent, 0};
            }else{
                parent = mp[descriptions[i][0]].first;
                
            }

            if(!mp.count(descriptions[i][1])){
                child = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]] = {child, 1};
            }else{
                child = mp[descriptions[i][1]].first;
                if(!mp[descriptions[i][1]].second){
                    mp[descriptions[i][1]].second = 1;
                }
            }
            
            if(descriptions[i][2]){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }

        for(auto const& m : mp){
            if(!m.second.second){
                root = m.second.first;
                break;
            }
        }
        return root;
    }
};