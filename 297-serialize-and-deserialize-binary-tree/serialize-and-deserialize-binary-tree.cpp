/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.append(to_string(root->val));
        ans.push_back(',');
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                    ans.append(to_string(curr->left->val));
                    ans.append(",");
                }else{
                    ans.append("n,");
                }
                if(curr->right){
                    q.push(curr->right);
                    ans.append(to_string(curr->right->val));
                    ans.append(",");
                }else{
                    ans.append("n,");
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');
        if(token=="n") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int j=0;j<n;j++){
                TreeNode* curr = q.front();
                q.pop();

                if(getline(ss, token, ',')){
                    if(token!="n"){
                        TreeNode* leftnode = new TreeNode(stoi(token));
                        curr->left = leftnode;
                        q.push(leftnode);
                    }
                }

                if(getline(ss, token, ',')){
                    if(token!="n"){
                        TreeNode* rightnode = new TreeNode(stoi(token));
                        curr->right = rightnode;
                        q.push(rightnode);
                    }
                }

            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));