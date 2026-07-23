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
class BSTIterator {
public:
    int start;
    vector<int> inorder;

    BSTIterator(TreeNode* root) {
        start = 0;
        inorder.push_back(-1);

        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }else{
                curr = st.top();
                st.pop();
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    
    int next() {
        start++;
        return inorder[start];        
    }
    
    bool hasNext() {
        return (start+1)<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */