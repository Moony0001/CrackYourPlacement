class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt (26,0);
        int maxi = INT_MIN;
        for(char c : tasks){
            cnt[c-'A']++;
            maxi = max(maxi, cnt[c-'A']);
        }

        int cmax = 0;
        for(int i=0;i<26;i++){
            if(cnt[i]==maxi){
                cmax++;
            }
        }
        int temp = (n+1)*(maxi-1) + cmax;
        int ans = max((int)tasks.size(), temp);
        
        return ans;
    }
};