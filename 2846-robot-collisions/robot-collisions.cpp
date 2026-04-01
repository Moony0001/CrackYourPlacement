class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n = positions.size();
        
        // 1. Create a list of original indices and sort them by position
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0); // Fills with 0, 1, 2... n-1
        
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; // Only store indices in the stack
        
        // 2. Simulate the collisions
        for(int id : ids) {
            if (directions[id] == 'R') {
                // 'R' robots just wait on the stack for an 'L' to come along
                st.push(id);
            } else {
                // Current robot is 'L'. It will smash into 'R' robots on the stack.
                while (!st.empty() && directions[st.top()] == 'R' && health[id] > 0) {
                    int top_id = st.top();
                    
                    if (health[top_id] > health[id]) {
                        // Stack robot ('R') wins
                        health[top_id] -= 1;
                        health[id] = 0; // Current robot dies
                    } 
                    else if (health[top_id] < health[id]) {
                        // Current robot ('L') wins
                        health[id] -= 1;
                        health[top_id] = 0; // Stack robot dies
                        st.pop(); // Remove the dead 'R' from stack
                    } 
                    else {
                        // Tie. Both die.
                        health[id] = 0;
                        health[top_id] = 0;
                        st.pop();
                    }
                }
                
                // If the 'L' robot survived all the 'R' robots, it gets added to the stack
                if (health[id] > 0) {
                    st.push(id);
                }
            }
        }
        
        // 3. Collect surviving healths in the ORIGINAL input order
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // Since we modified the health array in-place, dead robots have 0 health
            if (health[i] > 0) {
                ans.push_back(health[i]);
            }
        }
        
        return ans;
    }
};