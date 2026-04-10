class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return -1;
        vector<vector<int>> freq(n+1);
        for(int i=0;i<n;i++){
            freq[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(int i=0;i<n+1;i++){
            if(freq[i].size()>2){
                int j = 0;
                while(j+2<freq[i].size()){
                    int temp = abs(freq[i][j]-freq[i][j+1])+abs(freq[i][j+1]-freq[i][j+2])+abs(freq[i][j+2]-freq[i][j]);
                    ans = min(ans, temp);
                    j++;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};