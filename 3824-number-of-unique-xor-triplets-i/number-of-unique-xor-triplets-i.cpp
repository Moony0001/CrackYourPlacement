class Solution {
public:
    int leftmost(int x){
        x |= (x>>1);
        x |= (x>>2);
        x |= (x>>4);
        x |= (x>>8);
        x |= (x>>16);

        return x - (x>>1);
    }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }else if(n==3){
            return n+1;
        }
        int value = leftmost(n);
        value = (value << 1);

        return value;
    }
};