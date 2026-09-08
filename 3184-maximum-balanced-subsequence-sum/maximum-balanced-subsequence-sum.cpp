class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;
        long long res = INT_MIN;
        for(int i=0;i<n;i++){
            int x = nums[i] - i;
            long long curr = nums[i];
            auto it = mp.upper_bound(x);
            if(it!=mp.begin()){
                auto previt =  prev(it);
                curr = max((long long)curr, previt->second+nums[i]);
            }
            res = max(res, curr);
            if(it != mp.begin() && prev(it)->second >= curr){
                continue;
            }

            while(it != mp.end() && it->second <= curr){
                it = mp.erase(it);
            }

            mp[x] = curr;
        }
        return res;
    }
};