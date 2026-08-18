class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> ans (n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1){
                    q.push({i,j});
                    nums[i][j] = -1;
                }
            }
        }

        int dir [4][2] = {{-1,0}, {0,1}, {0,-1}, {1,0}};

        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int, int> node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for(int i=0;i<4;i++){
                    int dx = x + dir[i][0];
                    int dy = y + dir[i][1];

                    if(dx>=0 && dx<n && dy>=0 && dy<m && nums[dx][dy]!=-1){
                        ans[dx][dy] = ans[x][y] + 1;
                        q.push({dx, dy});
                        nums[dx][dy] = -1;
                    }
                }
            }
        }
        return ans;
    }
};