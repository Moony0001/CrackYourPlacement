class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = 0;
        int right = 0;
        for(int w : weights){
            right+=w;
            left = max(left, w);
        }

        while(left<right){
            int mid = left + (right-left)/2;

            int ships = 0;
            int temp = 0;
            for(int w: weights){
                if(temp+w<=mid){
                    temp+=w;
                }else{
                    ships++;
                    temp=w;
                }
            }
            ships++;

            if(ships>days){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};