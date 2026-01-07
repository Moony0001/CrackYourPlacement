class Solution {
public:
    long long maxi = LLONG_MIN;
    int maxProduct(TreeNode* root) {
        dfschange(root);
        int mod = 1000000007;
        long long total = root->val;
        dfsfind(root,total);
        int ans = maxi%mod;
        return ans;
    }

    int dfschange(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr) return root->val;
        int left = 0;
        int right = 0;
        if(root->left!=nullptr){
            left = dfschange(root->left);
        }
        if(root->right!=nullptr){
            right = dfschange(root->right);
        } 
        root->val = root->val+left+right;
        return root->val;
    }

    void dfsfind(TreeNode* root, long long total){
        maxi = max(((long long)root->val*(total-(long long)root->val)), maxi);
        if(root->left!=nullptr){
            dfsfind(root->left, total);
        }
        if(root->right!=nullptr){
            dfsfind(root->right, total);
        }
    }
};