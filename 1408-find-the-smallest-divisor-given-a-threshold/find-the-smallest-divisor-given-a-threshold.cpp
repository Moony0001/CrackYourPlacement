class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 0;
        for(int i: nums){
            right = max(right, i);
        }

        while(left<right){
            int mid = left+(right-left)/2;

            int sum = 0;
            for(int i : nums){
                sum += (i+mid-1)/mid;
            }
            if(sum>threshold){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        return left;
    }
};