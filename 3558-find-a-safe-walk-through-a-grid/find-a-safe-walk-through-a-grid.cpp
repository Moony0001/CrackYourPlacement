class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& nums, int health) {
        int n = nums.size();
        int m = nums[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        dq.push_front({0, 0});
        res[0][0] = nums[0][0];
        nums[0][0] = -1;
        int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++){
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];

                if(dx>=0 && dy>=0 && dx<n && dy<m && nums[dx][dy]!=-1){
                    if(res[dx][dy] > res[x][y]+nums[dx][dy]){
                        res[dx][dy] = res[x][y] + nums[dx][dy];
                    }
                    if(nums[dx][dy]==0){
                        dq.push_front({dx, dy});
                    }else{
                        dq.push_back({dx, dy});
                    }
                    nums[dx][dy] = -1;
                }
            }
        }
        int ans = res[n-1][m-1];
        return ((health-ans)>=1);
    }
};