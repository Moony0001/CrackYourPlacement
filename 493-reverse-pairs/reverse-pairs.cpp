class Solution {
public:
    int ans = 0;

    void merge(vector<int>&nums, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid+1;
        int tempr = mid+1;
        for(int i=low; i<=mid;i++){
            while(tempr<=high && nums[i]>2LL*nums[tempr]){
                tempr++;
            }
            ans+=(tempr-(mid+1));
        }
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }

        while(right<=high){
            temp.push_back(nums[right++]);
        }

        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }

    void mergesort(vector<int>&nums, int low, int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        return ans;
    }
};