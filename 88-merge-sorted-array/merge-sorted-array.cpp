class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        int s = m+n;
        while((i>=0 || j>=0)&& k>=0){
            if(i>=0 && j>=0 && nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                k--;
                j--;
            }else if(i>=0 && j>=0 && nums1[i]>=nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }else if(i<0){
                while(j>=0){
                    nums1[k]=nums2[j];
                    j--; k--;
                }
            }else if(j<0){
                while(i>=0){
                    nums1[k]=nums1[i];
                    i--; k--;
                }
            }
        }
    }
};