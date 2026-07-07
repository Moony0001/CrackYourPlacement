class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int n = g.size();
        int m = s.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        return j;
    }
};