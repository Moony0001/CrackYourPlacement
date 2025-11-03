class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size();
        // for(int i=0;i<n-1;i++){
        //     cost += min(neededTime[i],neededTime[i+1]);
        // }

        // for(int i=0;i<n-1;i++){
        //     if(colors[i]!=colors[i+1]){
        //         cost -= min(neededTime[i], neededTime[i+1]);
        //     }
        // }
        vector<int> currt;
        char curr = colors[0];
        currt.push_back(neededTime[0]);
        for(int i=1;i<n;i++){
            if(colors[i]==curr){
                currt.push_back(neededTime[i]);
            }else{
                if(currt.size()>1){
                    int maxi = 0;
                    long long sum = 0;
                    for(int t : currt){
                        sum+=t;
                        maxi = max(maxi, t);
                    }
                    cost+=(int)(sum-maxi);
                }
                curr = colors[i];
                currt.clear();
                currt.push_back(neededTime[i]);
            }

        }
        if(currt.size()>1){
            int maxi = 0;
            long long sum = 0;
            for(int t : currt){
                sum+=t;
                maxi = max(maxi, t);
            }
            cost+=(int)(sum-maxi);
        }

        return cost;
    }
};