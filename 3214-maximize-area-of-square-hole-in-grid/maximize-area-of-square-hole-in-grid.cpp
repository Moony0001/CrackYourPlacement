class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {      
        sort(hbars.begin(), hbars.end());
        sort(vbars.begin(), vbars.end());
        int i =0;
        int j =0;
        int maxv = INT_MIN;
        int maxh = INT_MIN;
        while(j<hbars.size()-1 && i<=j){
            if(hbars[j+1]-hbars[j]==1){
                j++;
            }else{
                int l = j-i+1;
                maxh = max(maxh, l+1);
                j++;
                i=j;
            }
        }
        maxh = max(maxh, j-i+2);
        i =0;
        j = 0;
        while(j<vbars.size()-1 && i<=j){
            if(vbars[j+1]-vbars[j]==1){
                j++;
            }else{
                int l = j-i+1;
                maxv = max(maxv, l+1);
                j++;
                i=j;
            }
        }
        maxv = max(maxv, j-i+2);
        int ans = min(maxh, maxv);
        return ans*ans;
    }
};