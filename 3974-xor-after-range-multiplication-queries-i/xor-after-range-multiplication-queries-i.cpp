class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int qsize = queries.size();
        int md = 1000000007;
        for(int i=0;i<qsize;i++){
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2]){
                nums[j] = ((long long)nums[j]*queries[i][3])%md;
            }
        }

        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};