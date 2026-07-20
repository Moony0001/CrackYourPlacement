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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode*,TreeNode*> mp;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    mp[curr->left] = curr;
                }

                if(curr->right){
                    q.push(curr->right);
                    mp[curr->right] = curr;
                    
                }
            }
        }

        queue<TreeNode*> dist;
        dist.push(target);

        vector<int> ans;
        int level = 0;

        unordered_set<TreeNode*> st;
        st.insert(target);


        while(!dist.empty()){
            if(level==k) break;
            int n = dist.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = dist.front();
                dist.pop();

                if(curr->left && !st.count(curr->left)){
                    dist.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right && !st.count(curr->right)){
                    dist.push(curr->right);
                    st.insert(curr->right);
                }
                if(mp[curr] && !st.count(mp[curr])){
                    dist.push(mp[curr]);
                    st.insert(mp[curr]);
                }

            }
            level++;
        }

        while(!dist.empty()){
            ans.push_back(dist.front()->val);
            dist.pop();
        }
        return ans;
    }
};