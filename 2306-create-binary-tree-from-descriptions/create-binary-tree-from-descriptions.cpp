class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        // Step 1: Build the tree and track all children
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];
            
            // If the parent or child doesn't exist yet, create them
            if (!nodes.count(parentVal)) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (!nodes.count(childVal)) {
                nodes[childVal] = new TreeNode(childVal);
            }
            
            // Attach the child to the parent
            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            
            // Record that this value is definitely a child
            children.insert(childVal);
        }
        
        // Step 2: Find the Root
        // The root is the ONLY node that never appears as a child
        for (auto& desc : descriptions) {
            if (!children.count(desc[0])) {
                return nodes[desc[0]];
            }
        }
        
        return nullptr;
    }
};