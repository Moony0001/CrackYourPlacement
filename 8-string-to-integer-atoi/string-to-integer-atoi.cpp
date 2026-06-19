class Solution {
public:
    int atoi(string s, int ans, int i, int sign){
        if(i==s.size() || s[i]<'0' || s[i]>'9'){
            return sign*ans;
        }

        int num = s[i]-'0';

        if((ans>(INT_MAX/10)) || (ans*10 > INT_MAX-num)){
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        ans = ans * 10 + num;
        return atoi(s, ans, i+1, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int sign = 1;

        while(i<s.size() && s[i]==' '){
            i++;
        }   

        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }
        return atoi(s, 0, i, sign);
    }
};