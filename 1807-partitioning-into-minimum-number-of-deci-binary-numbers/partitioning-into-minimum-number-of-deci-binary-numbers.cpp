class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        int m = n.size();
        int i=0;
        while(i<m){
            maxi = max(maxi, n[i]-'0');
            i++;
        }
        return maxi;
    }
};