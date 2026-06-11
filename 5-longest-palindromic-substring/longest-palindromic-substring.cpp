class Solution {
public:
    int expandcenter(string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return right-left-1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            int len1 = expandcenter(s, i, i);
            int len2 = expandcenter(s, i, i+1);
            int len = max(len1, len2);

            if(len>maxlen){
                start = i-(len-1)/2;
                maxlen = len;
            }
        }
        return s.substr(start, maxlen);
    }
};