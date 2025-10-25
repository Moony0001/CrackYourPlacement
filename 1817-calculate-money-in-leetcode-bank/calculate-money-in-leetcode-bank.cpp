class Solution {
public:
    int totalMoney(int n) {
        int a = n/7;
        int m = n%7;
        int sum = 28*a + ((a*(a-1)/2)*7)+(((a+m)*(a+m+1)/2)-(a*(a+1)/2));
        return sum;
    }
};