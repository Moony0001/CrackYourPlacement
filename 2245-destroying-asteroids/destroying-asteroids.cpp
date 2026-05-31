class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        bool ans = true;
        long long curr = mass;
        for(long long a : asteroids){
            if(curr>=a){
                curr+=a;
            }else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};