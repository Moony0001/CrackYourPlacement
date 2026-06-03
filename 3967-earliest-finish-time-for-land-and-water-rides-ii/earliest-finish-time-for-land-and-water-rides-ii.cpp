class Solution {
public:
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){
        int finish1 = INT_MAX;
        for(int i = 0;i<start1.size(); i++){
            finish1 = min(finish1, start1[i]+duration1[i]);
        }

        int finish2 = INT_MAX;
        for(int i=0;i<start2.size();i++){
            finish2 = min(max(finish1, start2[i])+duration2[i], finish2);
        }

        return finish2;
    }


    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int wl = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        int lw = solve(landStartTime, landDuration, waterStartTime, waterDuration);

        int ans = min(lw, wl);
        return ans;
        
    }
};