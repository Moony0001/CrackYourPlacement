class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int n = sum/9;
        vector<int> dig (n, 9);
        int m = sum%9;
        if(m>0){
            dig.push_back(m);
        }
        int s = dig.size();
        int t = num - s;
        if(t>=0){
            while(t--){
                dig.push_back(0);
            }
        }else {
            return "";
        }
        sort(dig.begin(), dig.end(), greater<int>());
        string ans = "";
        for(int i=0;i<dig.size();i++){
            ans += ('0' + dig[i]);
        }
        return ans;


    }
};