class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            mp[nums[j]] = j;

            while(mp.size()>k){
                int mini = INT_MAX;
                int key = -1;
                for(auto m : mp){
                    if(mini>m.second){
                        mini = m.second;
                        key = m.first;
                    }
                }
                mp.erase(key);
                i = mini+1;
            }

            if(mp.size()==k){
                int mini = INT_MAX;
                for(auto m : mp){
                    mini = min(mini, m.second);
                }
                ans += (mini-i+1);
            }
        }
        return ans;
    }
};