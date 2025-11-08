class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        if(k==0) return;
        if(gcd(n,k)==1){
            int temp = nums[i];
            int temp2 = 0;
            i = (i+k)%n;
            while(i!=0){
                temp2 = nums[i];
                nums[i]=temp;
                temp = temp2;
                i = (i+k)%n;
            }
            nums[i] = temp;
        }else{
            int y = gcd(n,k);
            for(int j = 0; j<y;j++){
                i = j;
                int temp = nums[i];
                int temp2 = 0;
                i = (i+k)%n;
                while(i!=j){
                    temp2 = nums[i];
                    nums[i]=temp;
                    temp = temp2;
                    i = (i+k)%n;
                }
                nums[i] = temp;
            }
        }

    }
};