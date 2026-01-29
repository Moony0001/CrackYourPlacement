class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int INF = 1000000000;
        vector<vector<int>> mat(26, vector<int>(26, INF));
        for (int i = 0; i < original.size(); i++) {
            mat[original[i] - 'a'][changed[i] - 'a'] =
                min(mat[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int i = 0; i < 26; i++) {
            mat[i][i] = 0;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (mat[j][i] < INF && mat[i][k] < INF) {
                        mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (mat[source[i] - 'a'][target[i] - 'a'] < INF) {
                ans += mat[source[i] - 'a'][target[i] - 'a'];
            } else {
                ans = -1;
                break;
            }
        }
        return ans;
    }
};