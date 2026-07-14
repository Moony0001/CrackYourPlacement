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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* f1 = q1.front();
            TreeNode* f2 = q2.front();
            q1.pop();
            q2.pop();

            if((f1==nullptr) ^ (f2==nullptr)){
                return false;
            }else{
                if(f1!=nullptr && f2!=nullptr){
                    if(f1->val != f2->val){
                        return false;
                    }
                }
            }
            if(f1!=nullptr && f2!=nullptr){
                if((f1->left==nullptr) ^ (f2->left==nullptr)){
                    return false;
                }else{
                    q1.push(f1->left);
                    q2.push(f2->left);
                }
                if((f1->right==nullptr) ^ (f2->right==nullptr)){
                    return false;
                }else{
                    q1.push(f1->right);
                    q2.push(f2->right);
                }
            }
            
        }

        return (q1.empty() && q2.empty());
    }
};