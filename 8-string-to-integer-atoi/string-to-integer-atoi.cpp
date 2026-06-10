class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int neg = 0;
        int ans = 0;
        
        while (i < n && s[i] == ' ') i++;
        
        if (i < n && s[i] == '-') {
            neg = 1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }
        
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';
                
                // If it exceeds INT_MAX/10, OR it equals INT_MAX/10 and digit is 8 or 9
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                    // For positive numbers, this is an overflow -> return INT_MAX
                    // For negative numbers, digit=8 returns INT_MIN (exact fit), digit=9 returns INT_MIN (overflow).
                    return neg ? INT_MIN : INT_MAX;
                }
                
                ans = ans * 10 + digit;
                i++;
            } else {
                break;
            }
        }
        
        if (neg) ans = ans * -1;
        
        return ans;
    }
};