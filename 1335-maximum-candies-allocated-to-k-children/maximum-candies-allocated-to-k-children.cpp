class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size();
        long long temp = 0;
        for(int i=0;i<n;i++){
            temp+=candies[i];
        }
        long long low = 0, high = temp/k;
        long long ans = 0;
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long tem = 0;
            for(int i=0;i<n;i++){
                if(mid>0){
                    tem += (long long)(candies[i]/mid);
                }else{
                    tem = k;
                    break;
                }                
            }
            if(tem<k){
                high = mid-1;
            }else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};