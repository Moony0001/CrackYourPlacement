class Solution {
public:
    bool ispalindrome(string& s, int start, int end){
        int left = start;
        int right = end;
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++; right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        for(int i=n-1;i>=0;i--){ //window size - 1 loop
            for(int j=0;j+i<n;j++){ //starting of string loop
                if(ispalindrome(s,j,j+i)){
                    return s.substr(j,i+1);
                }
            }
        }
        return "";
    }
};