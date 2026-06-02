class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = 0;
        for(int p : piles){
            right = max(right, p);
        }
        while(left<right){
            int mid = left + (right-left)/2;

            long long total = 0;
            for(int p : piles){
                total += (p+mid-1)/mid;
            }

            if(total<=h){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};