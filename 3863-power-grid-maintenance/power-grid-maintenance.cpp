#include <vector>
#include <string>
#include <numeric> // For std::iota
#include <algorithm> // For std::min, std::swap
#include <map>
#include <set>       // For std::set
#include <functional> 

using namespace std;

// DSU structure (private helper class)
class DSU {
public:
    vector<int> parent;
    vector<int> sz; // Use size for union-by-size
    vector<set<int>> online_members; // Each root stores its online members

    DSU(int c) {
        parent.resize(c + 1);
        sz.resize(c + 1, 1);
        online_members.resize(c + 1);
        
        for(int i = 1; i <= c; ++i) {
            parent[i] = i;
            online_members[i].insert(i); // Initially, all are online
        }
    }

    // Find with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Unite two components
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Union by size: merge smaller set into larger set
            if (sz[root_i] < sz[root_j]) {
                swap(root_i, root_j);
            }
            
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            
            // Merge the sets (C++17).
            // This efficiently moves all elements from root_j's set
            // into root_i's set.
            online_members[root_i].merge(online_members[root_j]);
        }
    }
    
    // Set a station offline
    void set_offline(int i) {
        int root = find(i);
        // O(log c) operation
        online_members[root].erase(i); 
    }
    
    // Get the smallest online ID in the component
    int get_min_online(int i) {
        int root = find(i);
        if (online_members[root].empty()) {
            return -1;
        }
        // *std::set::begin() is O(1)
        return *online_members[root].begin(); 
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        DSU dsu(c);
        vector<int> off(c + 1, 0); // 0 = online, 1 = offline
        vector<int> ans;

        // O(n * log(c) + c * log(c)) amortized
        for (const auto& conn : connections) {
            dsu.unite(conn[0], conn[1]);
        }

        // O(q * log c)
        for (const auto& q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 2) {
                // Type 2: Station goes offline
                if (off[x] == 0) { // Check if it's not already offline
                    off[x] = 1;
                    dsu.set_offline(x); // O(log c)
                }
            } else {
                // Type 1: Maintenance check
                if (off[x] == 0) {
                    ans.push_back(x); // O(1)
                } else {
                    // O(alpha(c)) to find root, O(1) to get min
                    ans.push_back(dsu.get_min_online(x)); 
                }
            }
        }
        
        return ans;
    }
};