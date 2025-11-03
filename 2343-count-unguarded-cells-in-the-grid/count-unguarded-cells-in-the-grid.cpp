class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> world (m, vector<int>(n,0));
        int g = guards.size();
        int w = walls.size();
        for(int i=0;i<g;i++){
            world[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<w;i++){
            world[walls[i][0]][walls[i][1]] = 2;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(world[i][j]==1){
                    int a = i+1;
                    while(a<m && world[a][j]!=1 && world[a][j]!=2){
                        world[a][j] = 3;
                        a++;
                    }
                    int b = j+1;
                    while(b<n && world[i][b]!=1 && world[i][b]!=2){
                        world[i][b]=3;
                        b++;
                    } 

                    b = j-1;
                    while(b>=0 && world[i][b]!=1 && world[i][b]!=2){
                        world[i][b]=3;
                        b--;
                    }

                    a = i-1;
                    while(a>=0 && world[a][j]!=1 && world[a][j]!=2){
                        world[a][j]=3;
                        a--;
                    } 
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(world[i][j]==0){
                    ans++;
                }
            }
        }

        return ans;
    }
};