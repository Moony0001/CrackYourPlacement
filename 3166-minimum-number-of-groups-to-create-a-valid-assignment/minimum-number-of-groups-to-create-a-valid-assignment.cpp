class Solution {
public:
    int grps(int num, int k){
        int groups = num/(k+1);
        int rem = num%(k+1);
        if(rem==0){
            return groups;
        }
        if(groups>=(k-rem)){
            return groups+1;
        }
        return -1;
    }

    int minGroupsForValidAssignment(vector<int>& balls) {
        map<int,int> mp;
        int n = balls.size();
        for(int i=0;i<n;i++){
            mp[balls[i]]++;
        }
        int mini = INT_MAX;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            mini = min(it->second, mini);
        }
        // int flag = 0;
        for(int i=mini;i>=0;i--){
            bool poss = true;
            int ans = 0;
            for(auto& it : mp){
                int group = grps(it.second, i);
                if(group==-1){
                    poss = false;
                    break;
                }
                ans+=group;
            }
            if(poss){
                return ans;
            }
        }
        return -1;
    }
};