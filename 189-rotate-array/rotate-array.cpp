class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int l = gcd(n, k);
        for(int i = 0;i<l;i++){
            int curr = nums[i];
            int next = 0;
            int j = (i+k)%n;
            int lim = i;
            while(j!=lim){
                next = nums[j];
                nums[j] = curr;
                curr = next;
                j=(j+k)%n;
                // i=(i+k)%n;
            }
            nums[j] = curr;
        }
        
        // return nums;
    }
};