class Solution {
public:
    static const int MOD = 1000000007;
    static const int MAXN = 100000;
    long long fact[MAXN];
    long long invFact[MAXN];

    long long binp(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while(exp>0){
            if(exp%2==1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    void precompute() {
        fact[0] = 1;
        invFact[0] = 1;
        
        for (int i = 1; i < MAXN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        invFact[MAXN - 1] = binp(fact[MAXN - 1], MOD - 2);
        
        for (int i = MAXN - 2; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int i) {
        if (i < 0 || i > n) return 0;
        
        long long num = fact[n];
        long long den = (invFact[i] * invFact[n - i]) % MOD;
        
        return (num * den) % MOD;
    }

    int maxdepth(vector<vector<int>> &adj, int curr, int parent){
        int maxi = 0;
        for(int a : adj[curr]){
            if(a!=parent){
                int maxd = maxdepth(adj, a, curr);
                maxi = max(maxd, maxi);
            }
        }
        return 1+maxi;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        precompute();
        int n = edges.size();
        vector<vector<int>> adj (n+1);

        for(auto e : edges){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = maxdepth(adj, 0, -1)-1;
        int ans = 0;
        for(int i=1;i<=depth;i+=2){
            ans = (ans + nCr(depth, i))%MOD;
        }
        return ans;
    }
};