class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        int ans = 0;
        int temp = x;
        while(temp>0){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && temp%10>7)){
                return false;
            }
            ans*=10;
            ans+=(temp%10);
            temp/=10;
        }
        if(ans==x){
            return true;
        }
        return false;
    }
};