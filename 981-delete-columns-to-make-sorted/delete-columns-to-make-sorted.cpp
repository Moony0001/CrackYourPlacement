class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        int m = strs[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                int curr = strs[j][i]-'a';
                int next = strs[j+1][i]-'a';
                if(curr>next){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};