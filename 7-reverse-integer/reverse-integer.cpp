class Solution {
public:
    int reverse(int x) {
        if(x<=-pow(2,31) || x>pow(2,31)-1){
            return 0;
        }
        int neg = 0;
        if(x<0){
            neg = 1;
        }
        int ans = 0;
        x = abs(x);
        while(x>0){
            if(ans > INT_MAX/10 || (ans==INT_MAX/10 && (x%10)>7)){
                return 0;
            }
            if(ans < INT_MIN/10 || (ans==INT_MIN/10 && (x%10)<-8)){
                return 0;
            }
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        if(neg){
            ans*=(-1);
        }
        return ans;
    }
};