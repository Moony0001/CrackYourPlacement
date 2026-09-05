class Solution {
public:
    int ans;

    void merge(vector<int>& nums, vector<int>& temp, int low, int mid, int high){
        int left = low, right = mid+1, i = low;

        int tempr = mid+1;
        for(int leftcount = low; leftcount<=mid; leftcount++){
            while(tempr <= high && nums[leftcount] > 2LL*nums[tempr]){
                tempr++;
            }
            ans += (tempr-(mid+1));
        }

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp[i++] = nums[left++];
            }else{
                temp[i++] = nums[right++];
            }
        }

        while(left<=mid){
            temp[i++] = nums[left++];
        }

        while(right<=high){
            temp[i++] = nums[right++];
        }

        for(int k=low;k<=high;k++){
            nums[k] = temp[k];
        }
    }

    void mergesort(vector<int>& nums, vector<int>& temp, int low, int high){
        if(low>=high) return;

        int mid = low + (high-low)/2;

        mergesort(nums, temp, low, mid);
        mergesort(nums, temp, mid+1, high);
        merge(nums, temp, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        int n = nums.size();
        vector<int> temp(n);
        mergesort(nums, temp, 0, n-1);
        return ans;
    }
};