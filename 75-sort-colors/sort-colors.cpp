class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Solved using Dutch national flag algorithm
        int n = nums.size();
        int i = 0;
        int m = 0;
        int j = n-1;
        while(m<=j){
            if(nums[m]<1){
                swap(nums[i],nums[m]);
                i++; m++;
            }else if(nums[m]>1){
                swap(nums[j],nums[m]);
                j--;
            }else{
                m++;
            }
        }
    }
};