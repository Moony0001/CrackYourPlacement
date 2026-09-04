class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        int cand1 = 0, cand2 = 1, cnt1 = 0, cnt2 = 0;

        for(int i : nums){
            if(cnt1 > 0 && i==cand1) cnt1++;
            else if(cnt2 > 0 && i==cand2) cnt2++;
            else if(cnt1==0){
                cand1 = i;
                cnt1 = 1;
            }else if(cnt2==0){
                cand2 = i;
                cnt2 = 1;
            }else{
                cnt1--; cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(int i : nums){
            if(i==cand1) cnt1++;
            else if(i==cand2) cnt2++;
        }

        if(cnt1 > n && cnt2 > n){
            return {cand1, cand2};
        }else if(cnt1 > n){
            return {cand1};
        }else if(cnt2 > n){
            return {cand2};
        }

        return {};
    }
};